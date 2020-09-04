/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekc_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:31:31 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/02 19:31:31 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int 	ft_check_max_d(char *str, int count, int znak)
{
	while (str[count] != '\0' && str[count] != ' ')
		count++;
	if (count == 10)
	{
		if ((znak == 1 || znak == 0) && ft_strncmp("2147483647", str, count) < 0)
			return (0);
		if (znak == -1 && ft_strncmp("2147483648", str, count) < 0)
			return (0);
	}
	else if (count > 10)
		return (0);
	return (1);
}

int 	ft_check_max(char *str)
{
	int i;
	int znak;

	znak = 0;
	i = 0;
	if (str[0] == '-')
		znak = -1;
	else if (str[0] == '+')
		znak = 1;
	if (znak != 0)
		i++;
	return (ft_check_max_d(&str[i], 0, znak));
}