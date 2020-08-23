/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:11:09 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/23 23:31:20 by sirvin           ###   ########.fr       */
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

void 	create_path(t_path *p, char *link, t_lemin *l)
{
	char **str;
	int i;

	p->count_room++;
	p->path = ft_strjoin(p->path, "-");
	str = ft_strsplit(l->links_name, '-');
	i = (ft_strequ(str[0], link)) ? 1 : 0;
	p->path = ft_strjoin(p->path, str[i]);
}

void 	dup_path(t_path *p)
{
	t_path *tmp;
	char *path;

	path = ft_strdup(p->path);
	tmp = ft_memalloc(sizeof(t_path));
	p->next = tmp;
	p = p->next;
	p->path = ft_strdup(path);
	p->next = NULL;
	free(path);

}

int 	search_path(t_lemin *l, int i, int number)
{
	t_path *p;
	t_lemin *head;
	t_path *head_p;
	int count;
	char *link;

	head = l;
	head_p = p;
	count = l->links;
	if (!(p = ft_memalloc(sizeof(t_path))))
		return (0);
	p->path = ft_strdup(l->start_name);
	be_zero_path(p, l);
	link = ft_strdup(l->start_name);
	number = count_links(l, link);
	while (count)
	{
		while (l)
		{
			while (number-- > 0)
			{
				if (search_name(link, l->links_name) && check_room_flag(head, l->links_name, link))
				{
					if (number > 1)
						dup_path(p);
					create_path(p, link, l);
					p = p->next;
					l = head;
				}
				else
					l = l->next;
			}
			link = pass_room(p->path);
			number = count_links(l, link);
		}
		l = head;
		p = head_p;
		link = pass_room(p->path);
		number = count_links(l, link);
		//Здесь ищем все связи с эндом, если в них флаг 1, то выходим из цикла
	}
}
