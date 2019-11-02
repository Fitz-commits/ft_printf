/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:01:29 by cdelaby           #+#    #+#             */
/*   Updated: 2019/10/26 19:01:33 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int count;
	int i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while(format[i])
	{
		if(format[i] == '%')
			count += conv_init(&format[i], ap, &i)
		else
		{
			count += write(1, format[i], 1)
			i++;
		}
	}
	return (count)
}
