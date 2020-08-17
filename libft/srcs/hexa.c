/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:18:11 by etristan          #+#    #+#             */
/*   Updated: 2020/07/17 18:21:39 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ullonghex(t_printf *f, char x)
{
	if (x == 'x')
	{
		f->n_print = f->n_print + write(1, "ffffffffffffffff\0", 16);
		return ;
	}
	else if (x == 'X')
	{
		f->n_print = f->n_print + write(1, "FFFFFFFFFFFFFFFF\0", 16);
		return ;
	}
}

void	right_hexa(t_printf *f, char *number, int numlen, char x)
{
	char c;

	c = (f->zero && !f->precis_status) ? '0' : ' ';
	if (c == '0' && x == 'x' && f->hash == 2)
		f->n_print += write(1, "0x", 2);
	else if (c == '0' && x == 'X' && f->hash == 2)
		f->n_print += write(1, "0X", 2);
	while (f->width-- > 0)
		f->n_print += write(1, &c, 1);
	if (c == ' ' && x == 'x' && f->hash == 2)
		f->n_print += write(1, "0x", 2);
	else if (c == ' ' && x == 'X' && f->hash == 2)
		f->n_print += write(1, "0X", 2);
	while (f->precision-- > 0)
		f->n_print += write(1, "0", 1);
	f->n_print += write(1, number, numlen);
	free(number);
}

void	left_hexa(t_printf *f, char *number, int numlen, char x)
{
	if (x == 'x' && f->hash == 2)
		f->n_print += write(1, "0x", 2);
	else if (x == 'X' && f->hash == 2)
		f->n_print += write(1, "0X", 2);
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, number, numlen);
	while (f->width > 0)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
	free(number);
}

void	parse_hexa(t_printf *f, uintmax_t num, char *str, char x)
{
	int	numlen;

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
		f->precision = f->precision - numlen;
	else
		f->precision = 0;
	f->width = f->width - (numlen + f->precision + f->hash);
	if (f->minus != 0)
		left_hexa(f, str, numlen, x);
	else
		right_hexa(f, str, numlen, x);
}

void	print_hexa(t_printf *f, va_list ap, char x)
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
	else if (f->modif == J)
		num = (uintmax_t)va_arg(ap, uintmax_t);
	str = (x == 'x') ? ft_itoa_base(num, 16, LOWER) :
			ft_itoa_base(num, 16, UPPER);
	if (num == ULLONG_MAX)
	{
		ullonghex(f, x);
		return ;
	}
	parse_hexa(f, num, str, x);
}
