/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:56:04 by etristan          #+#    #+#             */
/*   Updated: 2019/10/08 00:14:51 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lcell;
	t_list	*fst;

	if ((!lst && !f) || !(lcell = ft_lstnew(NULL, 0)))
		return (NULL);
	lcell = f(lst);
	fst = lcell;
	while (lst->next)
	{
		lst = lst->next;
		lcell->next = f(lst);
		lcell = lcell->next;
	}
	return (fst);
}
