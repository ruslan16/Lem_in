#include "unistd.h"
#include "stdlib.h"
#include "includes/lemin.h"

t_lemin 	*free_s(t_lemin *l)
{
	while (l->next != NULL)
	{
		free(l->room_name);
		free(l->links_name);
		l = l->next;
	}
	free(l->room_name);
	free(l->links_name);
	return (l);
}

t_lemin 	*ft_create_t(t_lemin *l)
{
	t_lemin *head;
	t_lemin *tmp;

	head = l;
	while (l->next != NULL)
		l = l->next;
	tmp = ft_memalloc(sizeof(t_lemin));
	l->next = tmp;
	l = l->next;
	l->room_name = ft_strdup("mom");
	l->links_name = ft_strdup("mom-kek");
	l->next = NULL;
	return (head);
}

t_lemin		*ft_create_new(t_lemin *l)
{
	t_lemin *head;
	t_lemin *tmp;

	head = l;
	while (l->next != NULL)
		l = l->next;
	tmp = ft_memalloc(sizeof(t_lemin));
	l->next = tmp;
	l = l->next;
	l->room_name = ft_strdup("kek");
	l->links_name = ft_strdup("kek-kek");
	l->next = NULL;
	return (head);
}

t_lemin 	*ft_create_struct(t_lemin *l)
{
	l->room_name = ft_strdup("lol");
	l->links_name = ft_strdup("lol-lol");
	l->next = NULL;
}

int 	main()
{
	t_lemin *l;

	l = ft_memalloc(sizeof(t_lemin));
	ft_create_struct(l);
	ft_create_new(l);
	ft_create_t(l);
	ft_printf("%s\n%s\n", l->room_name, l->links_name);
	l = l->next;
	ft_printf("%s\n%s\n", l->room_name, l->links_name);
	l = l->next;
	ft_printf("%s\n%s\n", l->room_name, l->links_name);
	return (0);
}