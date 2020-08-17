/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:36:19 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/15 14:57:15 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int 	search_room(char *str, t_lemin *l)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (i < l->rooms)
	{
		if (ft_strequ(str, l->room_name))
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}

void 	free_struct(t_lemin *l)
{
	free(l->end_name);
	free(l->start_name);
	free(l->room_name);
	free(l->links_name);
	free(l->coordinate);
}

void 	free_double(char **str)
{
	int i;

	i = 0;
	while (i < 3)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**double_strdup(char **str, int i)
{
	char **dup;

	dup = ft_memalloc(3);

	while (i < 3)
	{
		dup[i] = ft_strdup(str[i]);
		i++;
	}
	return (dup);
}

int 	check_isdigit(char *str, char *str2)
{
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	while (*str2 != '\0')
	{
		if (!ft_isdigit(*str2))
			return (0);
		str2++;
	}
	return (1);
}

int		count_minus(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			count++;
		i++;
	}
	return (count);
}

int 	count_space(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	return (count);
}