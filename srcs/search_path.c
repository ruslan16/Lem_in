/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:11:09 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/04 23:34:17 by sirvin           ###   ########.fr       */
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

	if (!p)
		return ;
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

void 	be_zero_flag(t_lemin *l, t_path *p)
{
	t_lemin *head;

	head = l;
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
	be_zero_flag(l, p);
}

t_path 	*move_p_list(t_path *p, t_lemin *l)
{
	while (search_name(l->end_name, p->path, l) && p->next != NULL)
		p = p->next;
	while (p->next != NULL && count_links(l, last_room_d(p, l)) == 0)
		p = p->next;
	return (p);
}

t_path 	*search_path_t(t_lemin *l, t_lemin *head, t_path *p, t_path *head_p)
{
	while (head->number > 0 && l)
	{
		if (search_name(head->link, l->links_name, head)
		&& check_room_flag(head, l->links_name, head->link))
		{
			if (search_name(head->end_name, l->links_name, head))
			{
				create_path(p, head->link, l, head);
				p = head_p;
				l = head;
				be_zero_room(l, p);
				break;
			}
			if (head->number > 1)
				dup_path(p);
			create_path(p, head->link, l, head);
			p = p->next;
			head->number--;
			l = head;
		}
		else
			l = l->next;
	}
	return (p);
}

void 	search_path_d(t_lemin *l, t_path *p, t_lemin *head, t_path *head_p)
{
	p = move_p_list(p, l);
	head->link = last_room(p, head);
	head->number = count_links(head, head->link);
	while (p && head->link && head->number)
	{
		p = search_path_t(l, head, p, head_p);
		if (!p)
			break;
		head->link = last_room(p, head);
		head->number = count_links(head, head->link);
		p = move_p_list(p, head);
	}
}

int 	search_path(t_lemin *l, t_path *p, int number, char *link)
{
	t_lemin *head;
	t_path *head_p;

	head = l;
	head_p = p;
	while (link && number && p)
	{
		search_path_d(l, p, head, head_p);
		l = head;
		p = head_p;
		p = move_p_list(p, l);
		link = last_room(head_p, head);
		number = count_links(l, link);
	}
	return (1);
	//return ((check_path(head, head_p) == 0 ? 0 : 1));
}

int		create_struct_p(t_lemin *l)
{
	t_path *p;
	int number;
	char *link;

	if (!(p = ft_memalloc(sizeof(t_path))))
		return (0);
	be_zero_path(p, l);
	p->path = ft_strdup(l->start_name);
	link = ft_strdup(l->start_name);
	number = count_links(l, link);
	if (!search_path(l, p, number, link))
		return (0);
	else
		return (1);
}