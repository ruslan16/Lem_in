/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:06:48 by etristan          #+#    #+#             */
/*   Updated: 2019/09/16 15:30:51 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	fnd;
	size_t	st;

	st = 0;
	if ((str == 0 && to_find == 0) || to_find[0] == '\0')
		return ((char *)str);
	else if (*str == '\0' || to_find == 0)
		return (0);
	while (str[st] != '\0' && (st < n))
	{
		fnd = 0;
		while (to_find[fnd] == str[st + fnd] && ((st + fnd) < n))
		{
			if (to_find[fnd + 1] == '\0')
				return ((char *)str + st);
			fnd++;
		}
		st++;
	}
	return (0);
}
