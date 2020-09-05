/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:40:40 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/05 21:44:42 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_ants	*move_ants_d(t_clpath *p, t_ants *a)
{
	t_ants *tmp;
	int name;

	name = 1;
	while (p)
	{
		while (p->ants-- > 0)
		{
			a->path = ft_strdup(p->path);
			a->name = name;
			tmp = ft_memalloc(sizeof(a));
			a->next = tmp;
			a = a->next;
			name++;
		}
		p = p->next;
	}
	return (a);
}

void 	move_ants(t_clpath *p)
{
	t_ants *a;
	t_ants *head_a;

	if (!(a = ft_memalloc(sizeof(a))))
		return ;
	head_a = a;
	a = move_ants_d(p, a);
	a->next = NULL;
	a = head_a;
	while (a)
	{
		ft_printf("%s\n%d\n", a->path, a->name);
		a = a->next;
	}
}