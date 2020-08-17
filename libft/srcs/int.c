/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:36:57 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:38:16 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_znak(t_printf *f, int znak)
{
	if (znak == POSITIV)
		f->n_print += write(1, "+", 1);
	else if (znak == NEGATIV)
		f->n_print += write(1, "-", 1);
}

void	ft_right_int(t_printf *f, char *number, int len, int znak)
{
	char c;

	c = (f->zero != 0) && (f->precis_status == 0) ? '0' : ' ';
	if (f->space)
		f->n_print += write(1, " ", 1);
	if (c == '0')
		ft_print_znak(f, znak);
	while (f->width > 0)
	{
		f->n_print += write(1, &c, 1);
		f->width--;
	}
	if (c == ' ')
		ft_print_znak(f, znak);
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, number, len);
}

void	ft_left_int(t_printf *f, char *number, int len, int znak)
{
	if (f->space != 0)
		f->n_print += write(1, " ", 1);
	if (znak == POSITIV)
		f->n_print += write(1, "+", 1);
	else if (znak == NEGATIV)
		f->n_print += write(1, "-", 1);
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, number, len);
	while (f->width > 0)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
}

void	ft_pars_int(t_printf *f, intmax_t num, int znak)
{
	int		numlen;
	char	*number;

	number = ft_itoa_base(num, 10, LOWER);
	if (znak != 0)
		f->space = 0;
	numlen = number_len(num, 10);
	if (num == 0)
		numlen = 1;
	if (f->precis_status == 1 && f->precision == 0 && num == 0)
		numlen = 0;
	if (f->precision > numlen)
		f->precision -= numlen;
	else
		f->precision = 0;
	if (znak != 0)
		f->width = f->width - (numlen + 1 + f->precision + f->space);
	else
		f->width = f->width - (numlen + f->precision + f->space);
	if (f->minus != 0)
		ft_left_int(f, number, numlen, znak);
	else
		ft_right_int(f, number, numlen, znak);
	free(number);
}

void	print_int(t_printf *f, va_list ap, int znak, intmax_t num)
{
	if (f->modif == 0)
		num = (int)va_arg(ap, int);
	else if (f->modif == H)
		num = (short int)va_arg(ap, int);
	else if (f->modif == HH)
		num = (signed char)va_arg(ap, int);
	else if (f->modif == L)
		num = (long int)va_arg(ap, long int);
	else if (f->modif == LL)
		num = (long long int)va_arg(ap, long long int);
	else if (f->modif == J)
		num = (intmax_t)va_arg(ap, long long int);
	if (f->plus == 1 && num >= 0)
		znak = POSITIV;
	else if (num < 0)
	{
		znak = NEGATIV;
		num = num * (-1);
	}
	if (num == LLONG_MIN)
		f->n_print += write(1, "-9223372036854775808", 20);
	else
		ft_pars_int(f, num, znak);
}
