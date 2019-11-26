/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toa1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:45:51 by cdelaby           #+#    #+#             */
/*   Updated: 2019/11/26 17:18:12 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int				get_size(long long nbr, int base)
{
	int i;

	i = 1;
	while (nbr / base)
	{
		i++;
		nbr = nbr / base;
	}
	return (i);
}

int				get_sizeu(unsigned long long nbr, int base)
{
	int		i;

	i = 1;
	while (nbr / base)
	{
		i++;
		nbr = nbr / base;
	}
	return (i);
}

char			*ctoa(int c)
{
	char	*result;

	if (!(result = malloc(sizeof(char) * 2)))
		return (NULL);
	result[0] = c;
	result[1] = 0;
	return (result);
}

char			*atoa(char *s)
{
	if (!s)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}

char			*xtoa(unsigned long long nb)
{
	char		*base;
	char		*result;
	int			size;

	base = ft_strdup("0123456789abcdef");
	size = get_sizeu(nb, 16);
	if (!(result = malloc(sizeof(char) * (get_sizeu(nb, 16) + 1))))
		return (NULL);
	result[size--] = 0;
	while (nb > 0)
	{
		result[size] = base[nb % 16];
		nb = nb / 16;
		size--;
	}
	free(base);
	return (result);
}
