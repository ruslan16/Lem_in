/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 00:00:36 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/26 22:21:17 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int 		check_double_link(char *line, t_lemin *l)
{
	char **link;
	char *str;

	link = ft_strsplit(line, '-');
	str = ft_strjoin(link[1], "-");
	str = ft_strjoin(str, link[0]);
	if (ft_strequ(str, l->links_name) || ft_strequ(line, l->links_name))
	{
		free(str);
		free_double(link, 2);
		return (0);
	}
	free(str);
	free_double(link, 2);
	return (1);
}

t_lemin		*check_link_name(t_lemin *l, char *line)
{
	t_lemin *head;
	char **link;
	int count;

	head = l;
	count = 0;
	link = ft_strsplit(line, '-');
	if ((ft_strequ(link[0], l->start_name) && !(ft_strequ(link[1], l->start_name)))
	|| (ft_strequ(link[0], l->end_name) && !(ft_strequ(link[1], l->end_name))))
		count++;
	if ((ft_strequ(link[1], l->start_name) && !(ft_strequ(link[0], l->start_name)))
	|| (ft_strequ(link[1], l->end_name) && !(ft_strequ(link[0], l->end_name))))
		count++;
	while (l)
	{
		if (ft_strequ(link[0], l->room_name) || ft_strequ(link[1], l->room_name))
			count++;
		l = l->next;
	}
	free_double(link, 2);
	return ((count == 2) ? head : NULL);
}

t_lemin 	*ft_check_links_d(char *line, t_lemin *l, int count)
{
	t_lemin *tmp;

	while (count-- > 0)
	{
		if (l->next == NULL)
		{
			if (!(tmp = ft_memalloc(sizeof(t_lemin))))
				return (NULL);
			l->next = tmp;
			l = l->next;
		}
		else
			l = l->next;
	}
	return (l);
}

t_lemin 	*ft_check_links(char *line, t_lemin *l)
{
	t_lemin *head;
	int count;

	count = l->links;
	l->links++;
	head = l;
	if (!check_link_name(l, line))
		return (NULL);
	if (!ft_check_links_d(line, l, count))
		return (NULL);
	while (count-- > 0)
		l = l->next;
	l->links_name = ft_strdup(line);
	ft_putstr(line);
	ft_putchar('\n');
	return (head);
}

t_lemin 	*create_link(t_lemin *l, char *line)
{
	l->links++;
	if (l->ants == 0 || l->rooms == 0)
		return (NULL);
	if (!check_link_name(l, line))
		return (NULL);
	l->links_name = ft_strdup(line);
	ft_putstr(line);
	ft_putchar('\n');
	return (l);
}
