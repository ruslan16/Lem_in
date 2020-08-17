/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:46:23 by etristan          #+#    #+#             */
/*   Updated: 2019/09/16 15:32:41 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t				i;
	unsigned const char	*s;
	unsigned char		sym;

	i = 0;
	if (*str == '\0' && str == 0)
		return (0);
	s = (unsigned const char *)str;
	sym = (unsigned char)c;
	while (s[i] != sym)
	{
		if (s[i] == 0)
			return (0);
		i++;
	}
	return ((char *)s + i);
}
