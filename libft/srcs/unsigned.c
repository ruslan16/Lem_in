/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:44:25 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:45:07 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_right_un(t_printf *f, char *number, int len)
{
	char c;

	c = (f->zero != 0) && (f->precis_status == 0) ? '0' : ' ';
	while (f->width > 0)
	{
		f->n_print += write(1, &c, 1);
		f->width--;
	}
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, number, len);
}

void	ft_left_un(t_printf *f, char *number, int len)
{
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

void	ft_pars_un(t_printf *f, uintmax_t num)
{
	int		numlen;
	char	*number;

	number = ft_itoa_base(num, 10, LOWER);
	numlen = ft_strlen(number);
	if (num == 0)
		numlen = 1;
	if (f->precis_status == 1 && f->precision == 0 && num == 0)
		numlen = 0;
	if (f->precision > numlen)
		f->precision -= numlen;
	else
		f->precision = 0;
	f->width = f->width - (numlen + f->precision + f->space);
	if (f->minus != 0)
		ft_left_un(f, number, numlen);
	else
		ft_right_un(f, number, numlen);
	free(number);
}

void	print_unsigned(t_printf *f, va_list ap, uintmax_t num)
{
	if (f->space)
		f->space = 0;
	if (f->modif == 0)
		num = (unsigned int)va_arg(ap, unsigned int);
	if (num == ULLONG_MAX)
	{
		write(1, "18446744073709551615", 20);
		return ;
	}
	else if (f->modif == H)
		num = (unsigned short int)va_arg(ap, int);
	else if (f->modif == HH)
		num = (unsigned char)va_arg(ap, int);
	else if (f->modif == L)
		num = (unsigned long int)va_arg(ap, long int);
	else if (f->modif == LL)
		num = (unsigned long long int)va_arg(ap, long long int);
	else if (f->modif == J)
		num = (uintmax_t)va_arg(ap, long long int);
	ft_pars_un(f, num);
}
