/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:13:05 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/05 21:47:13 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_LEMIN_H
#define LEMIN_LEMIN_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

typedef struct 		s_struct
{
	char *room_name;
	char *links_name;
	struct s_struct *next;
}					t_struct;

typedef struct		s_lemin
{
	int 			ants;
	int 			rooms;
	int 			links;
	int 			start;
	int 			end;
	int 			v;
	char 			*link;
	int 			number;
	char 			*start_name;
	char 			*end_name;
	char 			*start_coord;
	char 			*end_coord;
	char 			*room_name;
	char 			*links_name;
	char 			*coordinate;
	struct s_lemin	*next;
}					t_lemin;

typedef struct 		s_path
{
	char 			*path;
	int 			count_room;
	int 			ants;
	struct s_path	*next;
}					t_path;

typedef struct 		s_clpath
{
	char 			*path;
	int 			count_room;
	int 			ants;
	struct s_clpath	*next;
}					t_clpath;

typedef struct 		s_ants
{
	char 			*path;
	int 			name;
	struct s_ants	*next;
}					t_ants;

int			read_map(int fd, t_lemin *l, int i);
t_lemin 	*get_ant(t_lemin *l, char *line);
t_lemin 	*create_start(t_lemin *l, char *line);
t_lemin 	*create_end(t_lemin *l, char *line);
t_lemin 	*create_room(t_lemin *l, char *line);
t_lemin 	*ft_check_rooms(char *line, t_lemin *l);
t_lemin 	*check_rooms_d(t_lemin *l, char **room, char *line);
int 		check_double_name(char **room, t_lemin *l);
t_lemin 	*create_link(t_lemin *l, char *line);
t_lemin 	*ft_check_links(char *line, t_lemin *l);
int			create_struct_p(t_lemin *l);

int		check_path(t_lemin *l, t_path *p);

void 	move_ants(t_clpath *p);

int			count_space(char *line);
int			count_minus(char *line);
int			check_isdigit(char *str, char *str2);
void		free_double(char **str, int size);
void		free_struct(t_lemin *l);
int			search_name(char *name, char *str2, t_lemin *l);
int			check_room_flag(t_lemin *l, char *link, char *room_name);
int 		count_links(t_lemin *l, char *link);
char		*last_room(t_path *p, t_lemin *l);
char 		*last_room_d(t_path *p, t_lemin *l);
int			ft_check_max(char *str);

#endif
