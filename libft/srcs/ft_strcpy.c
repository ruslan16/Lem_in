/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 21:17:51 by etristan          #+#    #+#             */
/*   Updated: 2019/09/16 20:19:26 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		indx;

	indx = 0;
	while (src[indx] != '\0')
	{
		dest[indx] = src[indx];
		indx++;
	}
	dest[indx] = '\0';
	return (dest);
}
