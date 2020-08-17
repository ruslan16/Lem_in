/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:22:18 by etristan          #+#    #+#             */
/*   Updated: 2020/07/17 18:23:01 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_octal(t_printf *f, char *number, int len)
{
	char c;

	c = (f->zero && !f->precis_status) ? '0' : ' ';
	while (f->width > 0)
	{
		f->n_print += write(1, &c, 1);
		f->width--;
	}
	if (f->hash != 0)
		f->n_print += write(1, "0", 1);
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, number, len);
}

void	left_octal(t_printf *f, char *number, int len)
{
	if (f->hash != 0)
		f->n_print += write(1, "0", 1);
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

void	parse_octal(t_printf *f, uintmax_t num)
{
	int		numlen;
	char	*number;

	number = ft_itoa_base(num, 8, LOWER);
	numlen = ft_strlen(number);
	if (num == 0)
	{
		numlen = 1;
		if (f->hash == 1)
			numlen = 0;
		if (f->precis_status && f->precision == 0)
			numlen = 0;
	}
	if (f->precis_status && f->precision > numlen)
		f->precision = f->precision - (f->hash + numlen);
	else
		f->precision = 0;
	f->width = f->width - (f->hash + numlen + f->precision);
	if (f->minus != 0)
		left_octal(f, number, numlen);
	else
		right_octal(f, number, numlen);
	free(number);
}

void	print_octal(t_printf *f, va_list ap)
{
	uintmax_t num;

	num = 0;
	if (f->modif == 0)
		num = va_arg(ap, unsigned int);
	else if (f->modif == H)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (f->modif == HH)
		num = (unsigned char)va_arg(ap, unsigned int);
	else if (f->modif == L)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (f->modif == LL)
		num = (unsigned long long)va_arg(ap, unsigned long long);
	parse_octal(f, num);
}
