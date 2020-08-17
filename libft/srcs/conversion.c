/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:31:23 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:31:52 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion2(char c, t_printf *f, va_list ap)
{
	if (c == 'f')
		print_float(f, ap);
	else if (c == '%')
		print_percent(f);
	else if (c == 'b')
		print_binary(f, ap);
	else if (c == 'n')
		numer(f, ap);
	else if (c == 'K')
		color(f, ap);
	else if (c == 'y')
		palitra();
}

void	conversions(char c, t_printf *f, va_list ap)
{
	if (c == 'c')
		print_char(f, ap);
	else if (c == 's')
		print_string(f, ap);
	else if (c == 'p')
		print_pointer(f, ap);
	else if (c == 'd' || c == 'i')
		print_int(f, ap, 0, 0);
	else if (c == 'o')
		print_octal(f, ap);
	else if (c == 'u')
		print_unsigned(f, ap, 0);
	else if (c == 'x' || c == 'X')
		print_hexa(f, ap, c);
	else
		conversion2(c, f, ap);
}
