/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:29:49 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 22:20:27 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_printf *f)
{
	char c;

	if (f->zero && f->precis_status == 0)
		c = '0';
	else
		c = ' ';
	f->width -= 1;
	if (f->minus == 1)
	{
		write(1, "%", 1);
		while (f->width-- > 0)
			f->n_print += write(1, " ", 1);
	}
	else if (f->minus == 0)
	{
		while (f->width-- > 0)
			f->n_print += write(1, &c, 1);
		write(1, "%", 1);
	}
	f->n_print += 1;
}

void	charnull(t_printf *f)
{
	int n;

	n = 0;
	if (f->width > 0)
	{
		n = f->width - 1;
		if (f->minus == 0)
		{
			writespace(n);
			write(1, "", 1);
		}
		else if (f->minus > 0)
		{
			write(1, "", 1);
			writespace(n);
		}
		f->n_print += n + 1;
	}
	else
		f->n_print += write(1, "", 1);
}

void	print_char(t_printf *f, va_list ap)
{
	char	c;

	c = (unsigned char)va_arg(ap, int);
	if (c == 0)
	{
		charnull(f);
		return ;
	}
	if (f->width > 0)
	{
		f->width -= 1;
		f->n_print += f->width;
		if (f->minus == 0)
		{
			(f->zero == 1) ? writezeros(f->width) : writespace(f->width);
			f->n_print += write(1, &c, 1);
		}
		else
		{
			f->n_print += write(1, &c, 1);
			writespace(f->width);
		}
	}
	else
		f->n_print += write(1, &c, 1);
}
