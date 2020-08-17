/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:33:09 by etristan          #+#    #+#             */
/*   Updated: 2019/09/16 21:54:41 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s != 0)
	{
		i = 0;
		j = 0;
		while (s[i] != '\0' && ft_isspace(s[i]))
			i++;
		j = ft_strlen(&s[i]) - 1;
		while (s[i] != '\0' && ft_isspace(s[i + j]))
			j--;
		if ((str = ft_strnew(j + 1)) == 0)
			return (NULL);
		ft_strncpy(str, (s + i), (j + 1));
		return (str);
	}
	return (0);
}
