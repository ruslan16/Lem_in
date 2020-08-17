/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:42:16 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:42:57 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	left_string(t_printf *f, char *str, int len)
{
	if (f->precis_status && len > f->precision)
		len = f->precision;
	write(1, str, len);
	f->n_print += len;
	while (f->width > len)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
}

void	right_string(t_printf *f, char *str, int len)
{
	char c;

	if (f->zero == 1)
		c = '0';
	else
		c = ' ';
	if (f->precis_status && len > f->precision)
		len = f->precision;
	while (f->width > len)
	{
		f->n_print += write(1, &c, 1);
		f->width--;
	}
	write(1, str, len);
	f->n_print += len;
}

void	print_string(t_printf *f, va_list ap)
{
	char	*str;
	int		i;

	str = (char *)va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	i = ft_strlen(str);
	if (f->minus != 0)
		left_string(f, str, i);
	else
		right_string(f, str, i);
}
