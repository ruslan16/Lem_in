/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:29:48 by etristan          #+#    #+#             */
/*   Updated: 2019/09/14 19:13:26 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		sym;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	sym = (unsigned char)c;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == sym)
			return ((void *)d + (i + 1));
		i++;
	}
	return (0);
}
