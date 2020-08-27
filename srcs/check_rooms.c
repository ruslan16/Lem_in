/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 23:59:17 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/19 21:32:07 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int 		check_double_name(char **room, t_lemin *l)
{
	char *coordinate;

	coordinate = ft_strjoin(room[1], " ");
	coordinate = ft_strjoin(coordinate, room[2]);
	if ((ft_strequ(room[0], l->room_name)) || (ft_strequ(coordinate, l->coordinate))
		|| (ft_strequ(room[0], l->start_name)) || (ft_strequ(room[0], l->end_name))
		|| (ft_strequ(coordinate, l->start_coord)) || (ft_strequ(coordinate, l->end_coord)))
	{
		free(coordinate);
		return (0);
	}
	free(coordinate);
	return (1);
}

t_lemin 	*check_rooms_d(t_lemin *l, char **room, char *line)
{
	t_lemin *tmp;
	t_lemin *head;
	char *str;

	head = l;
	while (l->next != NULL)
	{
		if (check_double_name(room, l) == 0)
			return (NULL);
		l = l->next;
	}
	if (check_double_name(room, l) == 0)
		return (NULL);
	if (!(tmp = ft_memalloc(sizeof(t_lemin))))
		return (NULL);
	l->next = tmp;
	l = l->next;
	l->room_name = ft_strdup(room[0]);
	str = ft_strjoin(room[1], " ");
	l->coordinate = ft_strjoin(str, room[2]);
	l->next = NULL;
	free(str);
	ft_putstr(line);
	ft_putchar('\n');
	return (head);
}

t_lemin 	*ft_check_rooms(char *line, t_lemin *l)
{
	char **room;
	t_lemin *head;

	l->rooms++;
	head = l;
	room = ft_strsplit(line, ' ');
	if ((room[0][0] == 'L') || (check_isdigit(room[1], room[2]) == 0))
	{
		free_double(room, 3);
		return (NULL);
	}
	if (!(check_rooms_d(l, room, line)))
	{
		free_double(room, 3);
		return (NULL);
	}
	free_double(room, 3);
	return (head);
}

t_lemin 	*create_room(t_lemin *l, char *line)
{
	char **room;
	char *str;

	l->rooms++;
	if (l->ants == 0)
		return (NULL);
	room = ft_strsplit(line, ' ');
	if ((room[0][0] == 'L') || (check_isdigit(room[1], room[2]) == 0))
	{
		free_double(room, 3);
		return (NULL);
	}
	l->room_name = ft_strdup(room[0]);
	str = ft_strjoin(room[1], " ");
	l->coordinate = ft_strjoin(str, room[2]);
	l->next = NULL;
	free_double(room, 3);
	free(str);
	ft_putstr(line);
	ft_putchar('\n');
	return (l);
}