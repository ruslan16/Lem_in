/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:36:19 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/04 14:04:13 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		check_end_path(t_ants *a)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (a->next != NULL)
	{
		if (a->flag == 1)
			i++;
		a = a->next;
		j++;
	}
	if (i == j)
		return (0);
	return (1);
}

void 	do_flag(t_lemin *l, char *room, int i)
{
	if (!room)
		return ;
	while (l)
	{
		if (ft_strequ(l->room_name, room))
			l->v = i;
		l = l->next;
	}
}

char 	*last_room_d(t_path *p, t_lemin *l)
{
	char **path;
	char *link;
	int i;

	i = 0;
	if (!p)
		return (NULL);
	while (search_name(l->end_name, p->path, l))
		p = p->next;
	if (count_minus(p->path) == 0)
		return (p->path);
	path = ft_strsplit(p->path, '-');
	while (path[i])
		i++;
	link = ft_strdup(path[i - 1]);
	free_double(path, i);
	return (link);
}

char 	*last_room(t_path *p, t_lemin *l)
{
	char **path;
	char *link;
	int i;

	i = 0;
	if (!p)
		return (NULL);
	while (search_name(l->end_name, p->path, l) && p->next != NULL)
		p = p->next;
	if (count_minus(p->path) == 0)
		return (p->path);
	while (p)
	{
		if (count_minus(p->path) > 0)
		{
			path = ft_strsplit(p->path, '-');
			while (path[i])
				i++;
			link = ft_strdup(path[i - 1]);
			if (count_links(l, link) != 0)
				break;
		}
		i = 0;
		p = p->next;
	}
	free_double(path, i);
	if (count_links(l, link) == 0 || ft_strequ(link, l->end_name))
	{
		free(link);
		return (NULL);
	}
	return (link);
}

int 	count_links(t_lemin *l, char *link)
{
	int count;
	t_lemin *head;

	head = l;
	count = 0;
	while (l)
	{
		if (search_name(link, l->links_name, head) &&
		check_room_flag(head, l->links_name, link))
			count++;
		l = l->next;
	}
	return (count);
}

int		check_path_flag(t_lemin *l, char *room_name)
{
	while (l)
	{
		if (ft_strequ(l->room_name, room_name))
		{
			if (l->v == 1)
				return (0);
		}
		l = l->next;
	}
	return (1);
}

int		check_room_flag(t_lemin *l, char *link, char *room_name)
{
	char **links;
	int i;
	int res;

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
				res = 0;
			else
				res = 1;
		}
		l = l->next;
	}
	free_double(links, 2);
	return ((res == 0) ? 0 : 1);
}

int 	search_name(char *name, char *str2, t_lemin *l)
{
	char **links;
	int res;
	int i;

	links = ft_strsplit(str2, '-');
	i = 0;
	res = 0;
	while (links[i])
	{
		if (ft_strequ(name, links[i]))
			res = 1;
		if (!ft_strequ(name, l->start_name) && ft_strequ(links[i], l->start_name) && (count_minus(str2) == 1))
		{
			res = 0;
			break;
		}
		i++;
	}
	free_double(links, i);
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

int 	size_double(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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