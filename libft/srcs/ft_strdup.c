/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:54:13 by etristan          #+#    #+#             */
/*   Updated: 2019/09/16 20:23:10 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	while (src[j] != '\0')
		j++;
	if ((p = (char*)malloc(sizeof(*p) * (j + 1))) == NULL)
		return (0);
	i = 0;
	while (i < j)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
