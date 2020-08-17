/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:43:09 by sirvin            #+#    #+#             */
/*   Updated: 2020/07/17 18:44:12 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		power(intmax_t n, int i)
{
	long		k;
	long double	result;

	result = n;
	k = 0;
	if (i == 0)
		return (1);
	while (k < i - 1)
	{
		result = result * n;
		k++;
	}
	return (result);
}

void			writespace(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

void			writezeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

int				number_len(intmax_t num, int n)
{
	int nbrlen;

	nbrlen = 0;
	if (num < 0)
	{
		num = -num;
		nbrlen++;
	}
	while (num)
	{
		num = num / n;
		nbrlen++;
	}
	return (nbrlen);
}

char			*ft_itoa_base(uintmax_t value, uintmax_t base, int registr)
{
	char				*s;
	unsigned long long	n;
	int					i;

	i = 1;
	n = value;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	if (registr == LOWER)
		while (i-- > 0)
		{
			s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
			n /= base;
		}
	else if (registr == UPPER)
		while (i-- > 0)
		{
			s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
			n /= base;
		}
	return (s);
}
