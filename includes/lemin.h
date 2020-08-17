/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:13:05 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/17 14:57:14 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_LEMIN_H
#define LEMIN_LEMIN_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

typedef struct		s_lemin
{
	int 			ants;
	int 			rooms;
	int 			links;
	int 			start;
	int 			end;
	char 			*start_name;
	char 			*end_name;
	char 			*room_name;
	char 			*links_name;
	char 			*coordinate;
	struct s_lemin			*next;
}					t_lemin;

int 	read_map(int fd, t_lemin *l);
int		read_map_d(t_lemin *l);

int 	count_space(char *line);
int		count_minus(char *line);
int 	check_isdigit(char *str, char *str2);
char	**double_strdup(char **str, int i);
void 	free_double(char **str);
void 	free_struct(t_lemin *l);
int 	search_room(char *str, t_lemin *l);

#endif
