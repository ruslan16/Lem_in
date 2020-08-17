/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:06:48 by etristan          #+#    #+#             */
/*   Updated: 2019/09/09 19:02:21 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int fnd;
	int st;

	st = 0;
	if ((str[0] == '\0' && to_find[0] == '\0') || to_find[0] == '\0')
		return ((char *)str);
	else if (str[0] == '\0' || to_find[0] == '\0')
		return (0);
	while (str[st] != '\0')
	{
		fnd = 0;
		while (to_find[fnd] == str[st + fnd])
		{
			if (to_find[fnd + 1] == '\0')
			{
				return ((char *)str + st);
			}
			fnd++;
		}
		st++;
	}
	return (0);
}
