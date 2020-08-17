/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:28:55 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:29:28 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_binary(t_printf *f, char *number, int len)
{
	char c;

	c = (f->zero && !f->precis_status) ? '0' : ' ';
	if (c == '0' && f->hash != 0)
		f->n_print += write(1, "0b", 2);
	while (f->width-- > 0)
		f->n_print += write(1, &c, 1);
	if (c == ' ' && f->hash != 0)
		f->n_print += write(1, "0b", 2);
	while (f->precision-- > 0)
		f->n_print += write(1, "0", 1);
	f->n_print += write(1, number, len);
}

void	left_binary(t_printf *f, char *number, int len)
{
	if (f->hash != 0)
		f->n_print += write(1, "0b", 2);
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

void	parse_binary(t_printf *f, uintmax_t num, char *str)
{
	int numlen;

	numlen = ft_strlen(str);
	if (f->hash)
		f->hash = 2;
	if (num == 0)
	{
		numlen = 1;
		f->hash = 0;
		if (f->precis_status && f->precision == 0)
			numlen = 0;
	}
	if (f->precis_status && f->precision > numlen)
		f->precision = f->precision - (numlen + f->hash);
	else
		f->precision = 0;
	f->width = f->width - (numlen + f->precision + f->hash);
	if (f->minus != 0)
		left_binary(f, str, numlen);
	else
		right_binary(f, str, numlen);
}

void	print_binary(t_printf *f, va_list ap)
{
	char		*str;
	uintmax_t	num;

	num = 0;
	if (f->modif == 0)
		num = va_arg(ap, unsigned int);
	else if (f->modif == H)
		num = (unsigned short)va_arg(ap, int);
	else if (f->modif == HH)
		num = (unsigned char)va_arg(ap, int);
	else if (f->modif == L)
		num = (unsigned long)va_arg(ap, uintmax_t);
	else if (f->modif == LL)
		num = (unsigned long long)va_arg(ap, uintmax_t);
	str = ft_itoa_base(num, 2, LOWER);
	parse_binary(f, num, str);
}
