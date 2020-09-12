/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:05:07 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/17 19:16:32 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

void 	be_zero_struct(t_lemin *l)
{
	l->ants = 0;
	l->start = 0;
	l->end = 0;
	l->rooms = 0;
	l->links = 0;
	l->link = NULL;
	l->number = 0;
	l->start_name = NULL;
	l->start_coord = NULL;
	l->end_name = NULL;
	l->end_coord = NULL;
	l->links_name = NULL;
	l->room_name = NULL;
	l->coordinate = NULL;
	l->next = NULL;
}

int		main()
{
	t_lemin *l;

	if (!(l = ft_memalloc(sizeof(t_lemin))))
		return (0);
	be_zero_struct(l);
	if (read_map(0, l, 0) == 0)
		write(2, "Error\n", 6);
	//free_struct(l);
	//free(l);
	exit(0);
	return (0);
}