/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toa2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:46:05 by cdelaby           #+#    #+#             */
/*   Updated: 2019/11/11 14:46:06 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *x_majtoa(unsigned long long nb)
{
    char *base;
    char *result;
    int size;

    base = ft_strdup("0123456789ABCDEF");
    size = get_size(nb, 16);
    if (!(result = malloc(sizeof(char) * (get_size(nb, 16) + 1))))
        return (NULL);
    result[size--] = 0;
    while(nb > 0)
    {
        result[size] = base[nb % 16];
        nb = nb/16;
        size--;
    }
    free(base);
    return (result);
}
