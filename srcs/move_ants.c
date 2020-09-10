/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 21:45:10 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/06 17:45:58 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char 	*new_path(char **room, int i)
{
	char *str;

	while (room[i])
	{
		str = ft_strjoin(room[i], str);
		i++;
	}
	return (str);
}

void 	move_ants(t_ants *a, t_lemin *l)
{
	char	**room;
	t_ants	*head;
	t_lemin	*head_l;
	char 	*str;
	int 	i;

	head = a;
	head_l = l;
	while (a)
	{
		room = ft_strsplit(a->path, '-');
		i = (ft_strequ(l->start_name, room[0])) ? 1 : 0;
		str = ft_strjoin(a->name, room[i]);
		if (check_path_flag(l, room[i]))
		{
			do_flag(l, room[i], 1);
			ft_putstr(str);
			a->prev_room = ft_strdup(room[i]);
			free(a->path);
			a->path = new_path(room, i + 1);
		}
		free(str);
		free_double(room, size_double(room));
		a = a->next;
	}
}

t_ants	*name_ants_d(t_clpath *p, t_ants *a)
{
	t_ants *tmp;
	int name;
	char *tmp_a;

	name = 1;
	while (p)
	{
		while (p->ants-- > 0)
		{
			a->path = ft_strdup(p->path);
			tmp_a = ft_strjoin("L", ft_itoa(name));
			a->name = ft_strjoin(tmp_a, "-");
			free(tmp_a);
			tmp = ft_memalloc(sizeof(a));
			a->next = tmp;
			a = a->next;
			name++;
		}
		p = p->next;
	}
	return (a);
}

void 	name_ants(t_clpath *p, t_lemin *l)
{
	t_ants *a;
	t_ants *head_a;
	t_lemin *head;

	if (!(a = ft_memalloc(sizeof(a))))
		return ;
	head_a = a;
	a = name_ants_d(p, a);
	a->next = NULL;
	a = head_a;
	while (l)
	{
		l->v = 0;
		l = l->next;
	}
	l = head;
	//free_struct_p(p);
	//move_ants(a, l);
	while (a)
	{
		ft_printf("%s\n%s\n", a->path, a->name);
		a = a->next;
	}
}