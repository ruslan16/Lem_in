/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 22:20:37 by etristan          #+#    #+#             */
/*   Updated: 2020/07/17 22:21:30 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	numer(t_printf *f, va_list ap)
{
	int *address;

	address = (int*)va_arg(ap, int*);
	*address = f->n_print;
}
