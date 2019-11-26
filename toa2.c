/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toa2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:46:05 by cdelaby           #+#    #+#             */
/*   Updated: 2019/11/26 17:18:22 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*x_majtoa(unsigned long long nb)
{
	char		*base;
	char		*result;
	int			size;

	base = ft_strdup("0123456789ABCDEF");
	size = get_size(nb, 16);
	if (!(result = malloc(sizeof(char) * (get_size(nb, 16) + 1))))
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

char			*ptoa(void *ptr)
{
	char					*base;
	char					*result;
	unsigned long long		p;
	int						size;

	if (ptr == NULL)
		return (ft_strdup(""));
	base = ft_strdup("0123456789abcdef");
	p = (unsigned long long)ptr;
	size = get_sizeu(p, 16);
	if (!(result = malloc(sizeof(char) * size + 3)))
		return (NULL);
	size += 2;
	result[size--] = 0;
	result[0] = '0';
	result[1] = 'x';
	while (p > 0)
	{
		result[size] = base[p % 16];
		p = p / 16;
		size--;
	}
	free(base);
	return (result);
}
