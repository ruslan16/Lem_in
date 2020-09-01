/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 21:31:05 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/31 21:56:26 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void 	put_ants(t_lemin *l, t_clpath *p)
{
	int min;
	t_clpath *head;
	t_clpath *min_path;

	head = p;
	min = p->count_room + p->ants;
	min_path = p;
	while (l->ants > 0)
	{
		while (p->next != NULL)
		{
			if (min > p->count_room + p->ants)
			{
				min_path = p;
				p = p->next;
			}
			else
				p = p->next;
		}
		p = min_path;
		p->ants++;
		l->ants--;
		min = p->count_room + p->ants;
		p = head;
	}
	p = head;
	while (p)
	{
		ft_printf("%d\n %s\n", p->ants, p->path);
		p = p->next;
	}
}

void 	put_path(t_lemin *l, t_path *p, int count)
{
	t_clpath *path;
	t_clpath *tmp;
	t_clpath *head;

	if (!(path = ft_memalloc(sizeof(t_clpath))))
		return ;
	head = path;
	while (p)
	{
		if (search_name(l->end_name, p->path, l))
		{
			path->path = ft_strdup(p->path);
			path->count_room = p->count_room;
			path->ants = 0;
			tmp = ft_memalloc(sizeof(t_clpath));
			path->next = tmp;
			path = path->next;
		}
		p = p->next;
	}
	free(path->next);
	path->next = NULL;
	put_ants(l, head);
}

int		check_path(t_lemin *l, t_path *p)
{
	t_path	*head;
	int 	count;

	head = p;
	count = 0;
	while (p)
	{
		if (search_name(l->end_name, p->path, l))
			count++;
		p = p->next;
	}
	if (count == 0)
		return (0);
	put_path(l, head, 0);
	return (1);
}