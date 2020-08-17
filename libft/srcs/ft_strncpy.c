/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:21:34 by etristan          #+#    #+#             */
/*   Updated: 2019/09/10 17:21:16 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *source, size_t count)
{
	size_t				i;

	i = 0;
	if (dest == 0 && source == 0)
		return (0);
	ft_bzero(dest, count);
	while (source[i] != '\0' && i < count)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
