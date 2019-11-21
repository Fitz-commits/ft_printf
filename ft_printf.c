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
	va_list		ap;
	int			count;
	int			i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			i += conv_init((char*)&format[i + 1], ap, &count) + 1;
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
/*
 int		main()
 {
 	char *salut;
 	salut = ft_strdup("salut");
 	//ft_printf("%p\n", salut);
 	//printf("%p", salut);
 	int i, i2;
 	i = 5;
 	i = ft_printf("%00196.111x%-75.105s%00025.*d\n" ,488781920u,"nryaS{>sO$$uv",-11,-461358826);
 	i2 = printf("%00196.111x%-75.105s%00025.*d\n" ,488781920u,"nryaS{>sO$$uv",-11,-461358826);
 	//ft_printf("i == %d \ni == %d", i, i2);"%093.158x%0177X%--94c%--.27x" ,1943018631u,3317677193u,-102,531810136u
 	free(salut);
 }
 
*/