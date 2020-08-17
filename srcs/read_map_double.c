/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 23:19:48 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/15 15:09:23 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*int 	ft_create_room(t_lemin *l, char *line)
{
	char **room;

	room = ft_strsplit(line, ' ');
	l->room_name[l->rooms - 1] = ft_strdup(room[0]);
	free_double(room);
	return (1);
}

int 	ft_create_links(t_lemin *l, char *line)
{
	char **links;

	links = ft_strsplit(line, '-');
	if (search_room(links[0], l) == 0)
	{
		free_double(links);
		return (0);
	}
	else if (search_room(links[1], l) == 0)
	{
		free_double(links);
		return (0);
	}
	l->links_name[l->links - 1] = ft_strdup(line);
	free_double(links);
	return (1);
}

int 	parsing_d(t_lemin *l, char *line)
{
	if (count_space(line) == 2)
		return (ft_create_room(l, line));
	else if (count_minus(line) == 1)
		return (ft_create_links(l, line));
	else
		return (1);
}*/