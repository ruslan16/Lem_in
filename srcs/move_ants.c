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

    str = ft_strdup(room[i]);
    i++;
    while (room[i])
    {
        str = ft_strjoin(str, "-");
        str = ft_strjoin(str, room[i]);
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
    a->prev_room = NULL;
    write(1, "\n", 1);
    while (check_end_path(a))
    {
        while (a->next != NULL)
        {
        	if (a->flag != 1)
			{
				if (count_minus(a->path) >= 1)
					room = ft_strsplit(a->path, '-');
				else
				{
					room = ft_memalloc(sizeof(char*) * 1);
					room[0] = ft_strdup(a->path);
				}
				i = (ft_strequ(l->start_name, room[0])) ? 1 : 0;
				str = ft_strjoin(a->name, room[i]);
				if (check_path_flag(l, room[i]))
				{
					do_flag(l, a->prev_room, 0);
					do_flag(l, room[i], 1);
					ft_putstr(str);
					write(1, " ", 1);
					a->prev_room = ft_strdup(room[i]);
					free(a->path);
					if (!ft_strequ(room[i], l->end_name))
						a->path = new_path(room, i + 1);
					else
						a->flag = 1;
				}
			}
           // free(str);
            //free_double(room, size_double(room));
            a = a->next;
        }
        a = head;
        write(1, "\n", 1);
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
    head = l;
    while (l)
    {
        l->v = 0;
        l = l->next;
    }
    l = head;
    //free_struct_p(p);
    move_ants(a, l);
    //while (a)
    //{
      //  ft_printf("%s\n%s\n", a->path, a->name);
        //a = a->next;
  //  }
}