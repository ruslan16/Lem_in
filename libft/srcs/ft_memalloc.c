/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:52:23 by etristan          #+#    #+#             */
/*   Updated: 2019/09/23 17:06:58 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*m;

	if (size == 0)
		return (NULL);
	m = (void *)malloc(sizeof(void *) * size);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, size);
	return (m);
}
