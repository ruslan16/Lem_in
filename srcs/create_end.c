/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:56:52 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/19 14:00:32 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		check_double_end(char **room, t_lemin *l)
{
	char *coordinate;

	coordinate = ft_strjoin(room[1], " ");
	coordinate = ft_strjoin(coordinate, room[2]);
	if ((ft_strequ(room[0], l->room_name)) || (ft_strequ(coordinate, l->coordinate))
		|| (ft_strequ(room[0], l->start_name)) || (ft_strequ(coordinate, l->start_coord)))
	{
		free(coordinate);
		return (0);
	}
	free(coordinate);
	return (1);
}

t_lemin 	*check_end(char **room, t_lemin *l)
{
	char *coordinate;

	coordinate = ft_strjoin(room[1], " ");
	l->end_name = ft_strdup(room[0]);
	l->end_coord = ft_strjoin(coordinate, room[2]);
	l->end++;
	while (l->next != NULL)
	{
		if (check_double_end(room, l) == 0)
		{
			free(coordinate);
			return (NULL);
		}
		l = l->next;
	}
	if (check_double_end(room, l) == 0)
	{
		free(coordinate);
		return (NULL);
	}
}

t_lemin 	*create_end(t_lemin *l, char *line)
{
	char **room;
	t_lemin *head;

	head = l;
	if (l->ants == 0)
		return (NULL);
	room = ft_strsplit(line, ' ');
	if (!check_end(room, l))
	{
		free_double(room);
		return (NULL);
	}
	if ((room[0][0] == 'L') || (check_isdigit(room[1], room[2]) == 0))
	{
		free_double(room);
		return (NULL);
	}
	free_double(room);
	ft_putstr(line);
	ft_putchar('\n');
	return (head);
}