/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:00:16 by etristan          #+#    #+#             */
/*   Updated: 2019/10/28 21:49:17 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 42

char	*ft_ck_read(char **nl, char *sln);
int		ft_ck_line(const int fd, char **line, char **nl);
t_list	*list_fd_nl(const int fd);
int		get_next_line(const int fd, char **line);

#endif
