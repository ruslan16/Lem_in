/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:10:35 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/02 20:28:37 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemin 	*get_ant(t_lemin *l, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i]))
			return (NULL);
		i++;
	}
	l->ants = ft_atoi(line);
	if (l->ants <= 0)
		return (NULL);
	ft_putstr(line);
	ft_putchar('\n');
	return (l);
}

t_lemin 	*ft_check_commands(char *line, t_lemin *l)
{
	if (line[1] != '#')
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	else
	{
		if (ft_strequ("start", &line[2]) && l->start > 0)
			return (NULL);
		if (ft_strequ("end", &line[2]) && l->end > 0)
			return (NULL);
		if (ft_strequ("start", &line[2]) && l->start == 0)
		{
			ft_putstr("##start\n");
			l->start = 1;
		}
		else if (ft_strequ("end", &line[2]) && l->end == 0)
		{
			ft_putstr("##end\n");
			l->end = 1;
		}
	}
	return (l);
}

t_lemin		*parsing(char *line, t_lemin *l, int i)
{
	if (line[0] == '#')
		return (ft_check_commands(line, l));
	else if (l->start == 1 && count_space(line) == 2 && l->links == 0)
		return (create_start(l, line));
	else if (l->end == 1 && count_space(line) == 2 && l->links == 0)
		return (create_end(l, line));
	else if (l->rooms == 0 && count_space(line) == 2)
		return (create_room(l, line));
	else if (l->links == 0 && count_space(line) == 2)
		return (ft_check_rooms(line, l));
	else if (l->links == 0 && count_minus(line) == 1)
		return (create_link(l, line));
	else if (l->rooms != 0 && count_minus(line) == 1)
		return (ft_check_links(line, l));
	else if (l->ants == 0 && l->rooms == 0 && l->links == 0)
		return (get_ant(l, line));
	else
		return (NULL);
}

int 	read_map(int fd, t_lemin *l, int i)
{
	char *line;
	int res;
	t_lemin *head;

	res = 1;
	head = l;
	while (get_next_line(fd, &line))
	{
		if (!(parsing(line, l, i)))
		{
			free(line);
			res = 0;
			break;
		}
		free(line);
		i++;
	}
	l = head;
	if (l->rooms == 0 || l->links == 0 || l->start != 2 || l->end != 2)
		return (0);
	if (!res)
		return (0);
	else
		return (create_struct_p(l));
}