/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:36:19 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/23 22:39:49 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int 	count_links(t_lemin *l, char *link)
{
	int count;

	count = 0;
	while (l)
	{
		if (search_name(link, l->links_name) ||
		check_room_flag(l, l->links_name, link))
			count++;
		l = l->next;
	}
	return (count);
}

int		check_room_flag(t_lemin *l, char *link, char *room_name)
{
	char **links;
	int i;

	links = ft_strsplit(link, '-');
	if (ft_strequ(links[0], room_name))
		i = 1;
	else
		i = 0;
	while (l)
	{
		if (ft_strequ(l->room_name, links[i]))
		{
			if (l->v == 1)
				return (0);
			else
				return (1);
		}
		l = l->next;
	}
}

char 	**char_dup_rooms(t_lemin *l)
{
	char **rooms;
	int i;

	i = 0;
	rooms = ft_memalloc(sizeof(char*) * l->rooms);
	while (l->next != NULL)
	{
		rooms[i] = ft_strdup(l->room_name);
		l = l->next;
		i++;
	}
	rooms[i] = ft_strdup(l->room_name);
	return (rooms);
}

int 	search_name(char *name, char *str2)
{
	char **links;
	int res;

	links = ft_strsplit(str2, '-');
	if (ft_strequ(name, links[0]))
		res = 1;
	else if (ft_strequ(name, links[1]))
		res = 1;
	else
		res = 0;
	free_double(links, 2);
	return ((res == 1) ? 1 : 0);
}

void 	free_struct(t_lemin *l)
{
	free(l->end_name);
	free(l->start_name);
	free(l->room_name);
	free(l->links_name);
	free(l->coordinate);
}

void 	free_double(char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
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