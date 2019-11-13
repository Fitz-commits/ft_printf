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
			i += conv_init((char*)&format[i + 1], ap, &count) + 1;
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	return (count);
}

int		main()
{
	char *salut;
	salut = ft_strdup("salut");
	//ft_printf("%p\n", salut);
	//printf("%p", salut);
	ft_printf("%p\n", salut);
	printf("%p\n", salut);
	free(salut);
}
