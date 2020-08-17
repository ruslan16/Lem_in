/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:11:20 by etristan          #+#    #+#             */
/*   Updated: 2019/09/14 18:27:31 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	sym;
	size_t			i;

	src = (unsigned char *)arr;
	sym = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == sym)
			return ((void *)src + i);
		i++;
	}
	return (0);
}
