/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:37:30 by etristan          #+#    #+#             */
/*   Updated: 2019/09/18 16:15:42 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	ln;

	if (s != 0 && f != 0)
	{
		i = 0;
		ln = ft_strlen(s);
		while (i < ln)
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
