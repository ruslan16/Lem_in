/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:25:30 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:28:42 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(const char *format, t_printf *f)
{
	while (ft_strchr(ALLFLAGS, format[f->pos]))
	{
		if (format[f->pos] == '0')
			f->zero = 1;
		if (format[f->pos] == '+')
			f->plus = 1;
		if (format[f->pos] == '#')
			f->hash = 1;
		if (format[f->pos] == ' ')
			f->space = 1;
		if (format[f->pos] == '-')
			f->minus = 1;
		f->pos++;
	}
	if (f->plus == 1)
		f->space = 0;
}

void	check_width(const char *format, t_printf *f, va_list ap)
{
	if (format[f->pos] >= '0' && format[f->pos] <= '9')
	{
		f->width = ft_atoi(&format[f->pos]);
		while (format[f->pos] >= '0' && format[f->pos] <= '9')
			f->pos++;
	}
	else if (format[f->pos] == '*')
	{
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width = (f->width) * (-1);
		}
		while (format[f->pos] == '*')
			f->pos++;
	}
}

void	check_precision(const char *format, t_printf *f, va_list ap, int i)
{
	if (format[f->pos] == '.')
	{
		f->precis_status = 1;
		f->pos++;
		if (format[f->pos] >= '0' && format[f->pos] <= '9')
		{
			f->precision = ft_atoi(&format[f->pos]);
			while (format[f->pos] >= '0' && format[f->pos] <= '9')
				f->pos++;
		}
		else if (format[f->pos] == '*')
		{
			i = va_arg(ap, int);
			if (i >= 0)
				f->precision = i;
			else if (i < 0)
				f->precis_status = 0;
			while (format[f->pos] == '*')
				f->pos++;
		}
	}
}

void	check_modif(const char *format, t_printf *f)
{
	if (ft_strchr(ALLMODIF, format[f->pos]))
	{
		if (format[f->pos] == 'h')
		{
			if (format[f->pos + 1] == 'h')
				f->modif = HH;
			else if (format[f->pos - 1] != 'h')
				f->modif = H;
		}
		if (format[f->pos] == 'l' || format[f->pos] == 'z')
		{
			if (format[f->pos + 1] == 'l')
				f->modif = LL;
			else if (format[f->pos - 1] != 'l')
				f->modif = L;
		}
		if (format[f->pos] == 'L')
			f->modif = BIGL;
		if (format[f->pos] == 'j')
			f->modif = J;
		while (ft_strchr(ALLMODIF, format[f->pos]))
			f->pos++;
	}
}

void	argsflags(const char *format, t_printf *f, va_list ap)
{
	check_flags(format, f);
	check_width(format, f, ap);
	check_precision(format, f, ap, 0);
	check_modif(format, f);
}
