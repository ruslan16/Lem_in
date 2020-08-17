/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:38:30 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:40:29 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parstwo(const char *format, t_printf *f, va_list ap)
{
	if (!ft_strchr(ALLPREOBR, format[f->pos]))
		argsflags(format, f, ap);
	else if (ft_strchr(ALLPREOBR, format[f->pos]))
	{
		conversions(format[f->pos], f, ap);
		zero_struct_two(f);
	}
	return (f->pos - 1);
}

int		ft_parsing(const char *format, t_printf *f, va_list ap)
{
	while (format[f->pos] != '\0')
	{
		if (format[f->pos] != '%' && format[f->pos])
			f->n_print += write(1, &format[f->pos], 1);
		else if (format[f->pos] == '%')
		{
			if (!ft_strchr(ALLSYM, format[f->pos + 1]))
				return (-1);
			while (ft_strchr(ALLSYM, format[f->pos + 1]))
			{
				f->pos++;
				if (ft_strchr(ALLPREOBR, format[f->pos]))
				{
					f->pos = ft_parstwo(format, f, ap) + 2;
					break ;
				}
				else
					f->pos = ft_parstwo(format, f, ap);
			}
			continue ;
		}
		f->pos++;
	}
	return (f->n_print);
}
