/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:46:23 by etristan          #+#    #+#             */
/*   Updated: 2019/09/16 15:12:57 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int					i;
	int					ln;
	unsigned const char	*s;
	unsigned char		*d;

	i = 0;
	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	ln = ft_strlen(dest);
	while (s[i] != '\0')
	{
		d[ln + i] = s[i];
		i++;
	}
	d[ln + i] = '\0';
	return ((char *)d);
}
