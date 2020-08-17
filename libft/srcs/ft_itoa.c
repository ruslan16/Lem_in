/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:43:24 by etristan          #+#    #+#             */
/*   Updated: 2019/09/19 16:39:32 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	ns;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	ns = ft_numlen(n);
	if ((str = ft_strnew(ns)) == 0)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
		i++;
	}
	while (ns > i)
	{
		ns--;
		str[ns] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
