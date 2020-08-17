/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:54:28 by etristan          #+#    #+#             */
/*   Updated: 2019/09/19 14:31:59 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	ltr;
	size_t				i;
	int					min;

	ltr = 0;
	i = 0;
	min = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		min = 1 - 2 * (str[i++] == '-');
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		if (i > 19 || ltr >= 9223372036854775808ULL)
		{
			if (min == 1)
				return (-1);
			else
				return (0);
		}
		ltr = (ltr * 10) + (str[i] - 48);
		i++;
	}
	return (ltr * min);
}
