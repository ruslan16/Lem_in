/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:36:03 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:36:46 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	error(void)
{
	write(1, "", 0);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len_write;
	int			len_form;
	t_printf	*f;

	len_write = 0;
	len_form = ft_strlen(format);
	if (!(f = (t_printf*)malloc(sizeof(t_printf))))
		return (0);
	zero_struct(f);
	va_start(ap, format);
	if (!format[0])
	{
		free(f);
		error();
		return (0);
	}
	if (len_form == 1 && format[0] == '%')
		error();
	else
		len_write = ft_parsing(format, f, ap);
	va_end(ap);
	free(f);
	return (len_write);
}
