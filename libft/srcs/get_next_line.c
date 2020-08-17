/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:59:42 by etristan          #+#    #+#             */
/*   Updated: 2019/10/28 19:42:19 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_ck_read(char **nl, char *sln)
{
	char	*tmp;

	if ((*nl = ft_strchr(sln, '\n')))
	{
		tmp = ft_strsub(sln, 0, (*nl - sln));
		ft_strcpy(sln, ++(*nl));
	}
	else
	{
		tmp = ft_strnew(ft_strlen(sln));
		ft_strcat(tmp, sln);
		ft_strclr(sln);
	}
	return (tmp);
}

int		ft_ck_line(const int fd, char **line, char **nl)
{
	char	btmp[BUFF_SIZE + 1];
	int		ret;
	char	*sln;
	char	*tmp;
	int		clr;

	ret = 1;
	sln = NULL;
	*line = ft_ck_read(&sln, *nl);
	while (!sln && (ret = read(fd, btmp, BUFF_SIZE)))
	{
		btmp[ret] = '\0';
		if ((sln = ft_strchr(btmp, '\n')))
		{
			ft_strcpy(*nl, ++sln);
			ft_strclr(--sln);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, btmp)) || ret < 0)
			return (-1);
		free(tmp);
	}
	if (!(clr = ((ret || ft_strlen(*line) || ft_strlen(*nl)) ? 1 : 0)))
		ft_strdel(line);
	return (clr);
}

t_list	*list_fd_nl(const int fd)
{
	t_list	*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->content_size = (size_t)fd;
	new->content = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*first;
	t_list			*tmp;
	int				i;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (first == NULL)
		first = list_fd_nl(fd);
	tmp = first;
	while (tmp->content_size != (size_t)fd)
	{
		if (tmp->next == NULL)
			tmp->next = list_fd_nl(fd);
		tmp = tmp->next;
	}
	i = ft_ck_line(tmp->content_size, line, (char **)(&tmp->content));
	return (i);
}
