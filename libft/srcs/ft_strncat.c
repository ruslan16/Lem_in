/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:46:23 by etristan          #+#    #+#             */
/*   Updated: 2019/09/15 18:48:11 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t count)
{
	size_t		i;
	size_t		ln;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	ln = ft_strlen(dest);
	while (src[i] != '\0' && i < count)
	{
		dest[ln + i] = src[i];
		i++;
	}
	dest[ln + i] = '\0';
	return (dest);
}
