/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:34:50 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:35:45 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_float_afterdot(t_printf *f, t_float fl)
{
	if (fl.dot)
		f->n_print += write(1, ".", 1);
	while (fl.zeroes-- > 0 && fl.precision-- != 0)
		f->n_print += write(1, "0", 1);
	if (fl.precision)
		f->n_print += write(1, fl.strtail, ft_strlen(fl.strtail));
	while (fl.precisionaddon-- > 0)
		f->n_print += write(1, "0", 1);
}

void	right_float_beforedot(t_printf *f, t_float fl)
{
	if (f->space == 1 && fl.znak_status != 1)
		f->n_print += write(1, " ", 1);
	if ((fl.width > 0 && fl.c == '0') || fl.width < 0)
	{
		if (fl.znak_status && fl.znak)
			f->n_print += write(1, &fl.znak, 1);
		while (fl.width-- > 0)
			f->n_print += write(1, &fl.c, 1);
	}
	else if (fl.width > 0 && fl.c == ' ')
	{
		while (fl.width-- > 0)
			f->n_print += write(1, &fl.c, 1);
		if (fl.znak_status && fl.znak)
			f->n_print += write(1, &fl.znak, 1);
	}
	f->n_print += write(1, fl.strnum, ft_strlen(fl.strnum));
	right_float_afterdot(f, fl);
}

void	left_float(t_printf *f, t_float fl)
{
	if (f->space && fl.znak_status == 0)
		f->n_print += write(1, " ", 1);
	if (fl.znak_status && fl.znak)
		f->n_print += write(1, &fl.znak, 1);
	f->n_print += write(1, fl.strnum, ft_strlen(fl.strnum));
	if (fl.dot)
		f->n_print += write(1, ".", 1);
	while (fl.zeroes > 0 && fl.precision != 0)
	{
		f->n_print += write(1, "0", 1);
		fl.zeroes--;
		fl.precision--;
	}
	if (fl.precision)
		f->n_print += write(1, fl.strtail, ft_strlen(fl.strtail));
	while (fl.precisionaddon-- > 0)
		f->n_print += write(1, "0", 1);
	while (fl.width-- > 0)
		f->n_print += write(1, &fl.c, 1);
}
