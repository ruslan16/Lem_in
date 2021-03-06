/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:37:09 by etristan          #+#    #+#             */
/*   Updated: 2019/09/19 16:37:28 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(int n)
{
	size_t	ns;

	if (n == 0)
		return (1);
	ns = 0;
	if (n < 0)
		ns++;
	while (n != 0)
	{
		n = n / 10;
		ns++;
	}
	return (ns);
}
