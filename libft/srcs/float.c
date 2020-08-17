/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:32:08 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:34:40 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_float		parse_float_three(t_printf *f, t_float fl)
{
	if (fl.znak_status)
		f->space = 0;
	if (fl.tail == 0)
		fl.zeroes--;
	fl.dot = 0;
	if ((ft_strlen(fl.strtail) > 0 && fl.precision != 0) || f->hash)
		fl.dot = 1;
	fl.width = f->width - fl.precision - ft_strlen(fl.strnum)
			- fl.znak_status - fl.dot - f->space;
	fl.zeroes = fl.zeroes - fl.precisionaddon;
	if (f->minus)
		left_float(f, fl);
	else
		right_float_beforedot(f, fl);
	return (fl);
}

t_float		parse_float_two(t_printf *f, t_float fl, long double n)
{
	if (f->precis_status == 1 && f->precision >= 0)
		fl.precision = f->precision;
	fl.num = (long long)n;
	fl.strnum = ft_itoa_base(fl.num, 10, LOWER);
	n = n - (long double)fl.num;
	fl.precisionaddon = 0;
	if (n == 0)
		fl.precisionaddon = fl.precision - 1;
	n = n * power(10, fl.precision);
	fl.tail = (n >= 0) ? (long)(n + 0.5) : (long)(n - 0.5);
	if (fl.tail == power(10, fl.precision) && fl.tail != 0)
	{
		fl.strnum = ft_itoa_base(fl.num + 1, 10, LOWER);
		if (n == 0.5 && (int)fl.num % 2 == 0)
			fl.strnum = ft_itoa_base(fl.num, 10, LOWER);
		fl.tail = 0;
		if (fl.tail == 0)
			fl.precisionaddon = fl.precision - 1;
	}
	fl.strtail = ft_itoa_base(fl.tail, 10, LOWER);
	fl.zeroes = (fl.precision != 0) ?
		fl.precision - number_len(fl.tail, 10) : 0;
	return (fl);
}

void		parse_float_one(t_printf *f, long double n)
{
	t_float fl;

	fl.znak_status = 0;
	if (f->plus)
		fl.znak_status = 1;
	fl.znak = ' ';
	if (n < 0 || (n == 0 && (1 / n) < 0))
	{
		fl.znak_status = 1;
		fl.znak = '-';
		n = -n;
	}
	else if ((n > 0 && f->plus) || (n == 0 && f->plus))
		fl.znak = '+';
	fl.precision = 6;
	fl.c = f->zero ? '0' : ' ';
	if (f->minus || f->zero != 1)
		fl.c = ' ';
	fl = parse_float_two(f, fl, n);
	fl = parse_float_three(f, fl);
	free(fl.strnum);
	free(fl.strtail);
}

void		print_float(t_printf *f, va_list ap)
{
	long double n;

	n = 0.0;
	if (f->modif == 0)
		n = (long double)va_arg(ap, double);
	else if (f->modif == L)
		n = (long double)va_arg(ap, double);
	else if (f->modif == BIGL)
		n = (long double)va_arg(ap, long double);
	parse_float_one(f, n);
}
