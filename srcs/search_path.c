/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:11:09 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/28 00:26:29 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void 	be_zero_path(t_path *p, t_lemin *l)
{
	p->path = NULL;
	p->count_room = 0;
	p->ants = 0;
	p->next = NULL;
}

void 	create_path(t_path *p, char *link, t_lemin *l, t_lemin *head)
{
	char **str;
	int i;

	p->count_room++;
	p->path = ft_strjoin(p->path, "-");
	str = ft_strsplit(l->links_name, '-');
	i = (ft_strequ(str[0], link)) ? 1 : 0;
	p->path = ft_strjoin(p->path, str[i]);
	while (head)
	{
		if (ft_strequ(str[i], head->room_name))
			head->v = 1;
		head = head->next;
	}
}

void 	dup_path(t_path *p)
{
	t_path *tmp;
	t_path *list;
	char *path;
	int c_room;

	path = ft_strdup(p->path);
	c_room = p->count_room;
	tmp = ft_memalloc(sizeof(t_path));
	list = p->next;
	p->next = tmp;
	p = p->next;
	p->path = ft_strdup(path);
	p->count_room = c_room;
	p->next = list;
	free(path);
}

void 	be_zero_room(t_lemin *l, t_path *p)
{
	t_lemin *head;
	t_path *head_p;

	head = l;
	head_p = p;
	while (p)
	{
		if (!search_name(l->end_name, p->path, head))
		{
			free(p->path);
			p->path = ft_strdup(l->start_name);
			p->count_room = 0;
		}
		p = p->next;
	}
	p = head_p;
	while (l)
	{
		l->v = 0;
		l = l->next;
	}
	l = head;
	while (p)
	{
		if (count_minus(p->path) > 0)
		{
			while (l)
			{
				if (search_name(l->room_name, p->path, head))
					l->v = 1;
				l = l->next;
			}
			l = head;
		}
		p = p->next;
	}
}

int 	search_path(t_lemin *l, int number)
{
	t_path *p;
	t_lemin *head;
	t_path *head_p;
	char *link;

	head = l;
	if (!(p = ft_memalloc(sizeof(t_path))))
		return (0);
	be_zero_path(p, l);
	p->path = ft_strdup(l->start_name);
	head_p = p;
	link = ft_strdup(l->start_name);
	number = count_links(l, link);
	while (link)
	{
		while (l)
		{
			while (number > 0 && l)
			{
				if (search_name(link, l->links_name, head) && check_room_flag(head, l->links_name, link))
				{
					if (search_name(head->end_name, l->links_name, head))
					{
						create_path(p, link, l, head);
						p = head_p;
						l = head;
						be_zero_room(l, p);
						break;
					}
					if (number > 1)
						dup_path(p);
					create_path(p, link, l, head);
					//ft_printf("%s\n", p->path);
					p = p->next;
					l = head;
					number--;
				}
				else
					l = l->next;
			}
			if (!p)
				break;
			link = last_room(p, head);
			while (search_name(head->end_name, p->path, head))
				p = p->next;
			number = count_links(head, link);
			if (!link || !number)
				break;
		}
		l = head;
		p = head_p;
		link = last_room(p, head);
		while (search_name(l->end_name, p->path, l))
			p = p->next;
		number = count_links(l, link);
		if (!link || !number)
			break;
	}
	return (1);
}
