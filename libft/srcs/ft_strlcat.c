/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:46:23 by etristan          #+#    #+#             */
/*   Updated: 2019/09/15 18:48:11 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t		i;
	size_t		ln;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (dest[i] != '\0' && i < count)
		i++;
	ln = i;
	while (src[i - ln] != '\0' && (i + 1) < count)
	{
		dest[i] = src[i - ln];
		i++;
	}
	if (ln < count)
		dest[i] = '\0';
	return (ln + ft_strlen(src));
}
