/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:04:08 by etristan          #+#    #+#             */
/*   Updated: 2019/09/16 20:29:36 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 != 0 && s2 != 0)
	{
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (str == 0)
			return (NULL);
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
		return (str);
	}
	return (0);
}
