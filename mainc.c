#include "unistd.h"
#include "stdlib.h"
#include "includes/lemin.h"

void	free_s(t_struct *l)
{
	t_struct *tmp;

	tmp = NULL;
	while (l)
	{
		tmp = l;
		free(l->room_name);
		free(l->links_name);
		l = tmp->next;
		free(tmp);
	}
}

void 	ft_create_t(t_struct *l)
{
	t_struct *tmp;

	while (l->next != NULL)
		l = l->next;
	tmp = ft_memalloc(sizeof(t_struct));
	l->next = tmp;
	l = l->next;
	l->room_name = ft_strdup("mom");
	l->links_name = ft_strdup("mom-kek");
	l->next = NULL;
}

void 	ft_create_new(t_struct *l)
{
	t_struct *tmp;

	while (l->next != NULL)
		l = l->next;
	tmp = ft_memalloc(sizeof(t_struct));
	l->next = tmp;
	l = l->next;
	l->room_name = ft_strdup("kek");
	l->links_name = ft_strdup("kek-kek");
	l->next = NULL;
}

void	ft_create_struct(t_struct *l)
{
	l->room_name = ft_strdup("lol");
	l->links_name = ft_strdup("lol-lol");
	l->next = NULL;
}

int 	main()
{
	t_struct *l;
	t_struct *head;

	l = ft_memalloc(sizeof(t_struct));
	head = l;
	l->room_name = NULL;
	l->links_name = NULL;
	ft_create_struct(l);
	ft_create_new(l);
	ft_create_t(l);
	while (l)
	{
		ft_printf("%s\n%s\n", l->room_name, l->links_name);
		l = l->next;
	}
	free_s(l);
	return (0);
}