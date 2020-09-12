/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 21:31:05 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/06 15:02:36 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_clpath	*put_ants_d(t_clpath *p, t_clpath *min_path, int min)
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
	return (min_path);
}

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
		min_path = put_ants_d(p, min_path, min);
		p = min_path;
		p->ants++;
		l->ants--;
		min = p->count_room + p->ants;
		p = head;
	}
	//while (p)
	//{
	//	ft_printf("%s\n%d\n", p->path, p->ants);
	//	p = p->next;
	//}
	name_ants(p, l);
}

t_clpath	*put_path_d(t_clpath *path, t_path *p)
{
	t_clpath *tmp;

	path->path = ft_strdup(p->path);
	path->count_room = p->count_room;
	path->ants = 0;
	tmp = ft_memalloc(sizeof(t_clpath));
	path->next = tmp;
	path = path->next;
	return (path);
}

void 	put_path(t_lemin *l, t_path *p)
{
	t_clpath *path;
	t_clpath *head;
	t_path *head_p;

	if (!(path = ft_memalloc(sizeof(t_clpath))))
		return ;
	head = path;
	while (p)
	{
		if (search_name(l->end_name, p->path, l))
			path = put_path_d(path, p);
		p = p->next;
	}
	p = head_p;
	//free_struct_p(p);
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
	put_path(l, head);
	return (1);
}