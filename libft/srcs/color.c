/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:40:11 by etristan          #+#    #+#             */
/*   Updated: 2020/07/17 23:41:32 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_color(int i)
{
	ft_putstr("\x1b[38;5;");
	ft_putnbr(i);
	ft_putstr("m ");
	ft_putstr("\x1b[48;5;");
	ft_putnbr(i);
	ft_putstr("m ");
	ft_putnbr(888);
	ft_putstr(" \x1b[0m");
}

void	palitra(void)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (i++ <= 254)
	{
		write_color(i);
		if (j >= 7 && i > 14)
		{
			j = 1;
			ft_putchar('\n');
		}
		if (i % 2 && i <= 15)
			ft_putstr("\n\n");
		j++;
	}
	ft_putchar('\n');
}

void	color(t_printf *f, va_list ap)
{
	char	*str;
	int		i;
	char	j;

	i = 0;
	j = '1';
	str = (char *)va_arg(ap, char*);
	while (str[i] != '\0')
	{
		if (j == '9')
			j = '1';
		f->n_print += write(1, "\x1b[38;5;", 7);
		f->n_print += write(1, &j, 1);
		f->n_print += write(1, "m", 1);
		f->n_print += write(1, &str[i], 1);
		f->n_print += write(1, "\x1b[0m", 4);
		i++;
		j++;
	}
}
