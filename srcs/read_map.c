/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:21:28 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/18 01:02:04 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemin 	*check_rooms_d(t_lemin *l, char **room, char *line)
{
	t_lemin *tmp;

	if (!(tmp = ft_memalloc(sizeof(t_lemin))))
		return (NULL);
	l->next = tmp;
	l = l->next;
	l->room_name = ft_strdup(room[0]);
	l->next = NULL;
	//так же помещаем room[1],room[2] в l->coordinate, предварительно соединив две строчки, между собой пробелами.
	ft_putstr(line);
	ft_putchar('\n');
	return (l);
}

t_lemin 	*ft_check_rooms(char *line, t_lemin *l)
{
	char **room;
	t_lemin *head;

	l->rooms++;
	head = l;
	room = ft_strsplit(line, ' ');
	if ((room[0][0] == 'L') || (check_isdigit(room[1], room[2]) == 0))
	{
		free_double(room);
		return (NULL);
	}
	while (l->next != NULL)
		l = l->next;
	check_rooms_d(l, room, line);
	free_double(room);
	return (head);
}

t_lemin 	*ft_check_links(char *line, t_lemin *l)
{
	t_lemin *head;
	t_lemin *tmp;
	int count;

	l->links++;
	count = l->links - 1;
	head = l;
	while (count-- > 0)
	{
		if (l->next == NULL)
		{
			if (!(tmp = ft_memalloc(sizeof(t_lemin))))
				return (NULL);
			l->next = tmp;
			l = l->next;
		}
		else
			l = l->next;
	}
	l->links_name = ft_strdup(line);
	//Проверяем каждую строку links на то, что такая существует в l->room_name, если кол-во совпадений не равно 1,
	//то возвращаем 0.
	ft_putstr(line);
	ft_putchar('\n');
	return (head);
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

t_lemin 	*create_link(t_lemin *l, char *line)
{
	l->links++;
	if (l->ants == 0 || l->rooms == 0)
		return (NULL);
	l->links_name = ft_strdup(line);
	ft_putstr(line);
	ft_putchar('\n');
	return (l);
}

t_lemin 	*create_room(t_lemin *l, char *line)
{
	char **room;

	l->rooms++;
	if (l->ants == 0)
		return (NULL);
	room = ft_strsplit(line, ' ');
	if ((room[0][0] == 'L') || (check_isdigit(room[1], room[2]) == 0))
	{
		free_double(room);
		return (NULL);
	}
	l->room_name = ft_strdup(room[0]);
	//Здесь объединяем две строки room[1] and room[2] и кладём их в l->coordinate
	l->next = NULL;
	free_double(room);
	ft_putstr(line);
	ft_putchar('\n');
	return (l);
}

t_lemin 	*create_start_end(t_lemin *l, char *line, char name)
{
	char **room;

	if (l->ants == 0)
	{
		free_double(room);
		return (NULL);
	}
	room = ft_strsplit(line, ' ');
	if ((room[0][0] == 'L') || (check_isdigit(room[1], room[2]) == 0))
	{
		free_double(room);
		return (NULL);
	}
	if (name == 's')
		l->start_name = strdup(room[0]);
	else
		l->end_name = strdup(room[0]);
	(name == 's') ? l->start++ : l->end++;
	free_double(room);
	ft_putstr(line);
	ft_putchar('\n');
	return (l);
}

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

t_lemin		*parsing(char *line, t_lemin *l, int i)
{
	if (line[0] == '#')
		return (ft_check_commands(line, l));
	else if (l->start == 1 && count_space(line) == 2 && l->links == 0)
		return (create_start_end(l, line, 's'));
	else if (l->end == 1 && count_space(line) == 2 && l->links == 0)
		return (create_start_end(l, line, 'e'));
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

int 	read_map(int fd, t_lemin *l)
{
	int i;
	char *line;
	int res;

	i = 0;
	res = 1;
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
	if (l->rooms == 0 || l->links == 0 || l->start != 2 || l->end != 2)
		return (0);
	//Здесь надо ещё проверить, что нет комнат с одинаковым именем или координатами, а так же,
	//что нет дублирующих линкво по типу 1-2 2-1. Комнаты проверяем через функцию strequ,проверяем именя, бегая
	//по структуре с головы до NULL,если совпадений больше 1, то ошибка, так делаем с каждым именем.
	//Проверка координат соответствуюая, бегаем по всем координатам, если совпадений больше 1, то ошибка
	//проверяем каждый l->coordinate.
	//Линки проверяем следующим образом. Создаём 2-ый массив, сплитим по "-", начинаем бегать по всей структуре, сплитя каждый l->links_name
	//мы проверяем сразу две строчки(2 коорлинаты), если совпадений 2, то возвращаем ошибку.
	//ft_printf("%d\n", l->ants);
	//ft_printf("%d\n", l->rooms);
	//ft_printf("%d\n", l->links);
	ft_printf("\n%s\n", l->room_name);
	l = l->next;
	ft_printf("\n%s\n", l->room_name);
	l = l->next;
	ft_printf("\n%s\n", l->room_name);
	if (!res)
		return (0);
	else
		return (1);//return (read_struct(l));
}