/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:55:44 by cdelaby           #+#    #+#             */
/*   Updated: 2019/11/26 15:55:47 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_search(char c)
{
	int			j;
	char		*temp;

	j = 0;
	if (!(temp = ft_strdup("cspdiuxX%")))
		return (-1);
	while (temp[j])
	{
		if (temp[j] == c)
		{
			free(temp);
			return (j);
		}
		j++;
	}
	free(temp);
	return (j);
}

char		*converter(t_flag *flags, va_list ap)
{
	int		n;

	n = conv_search(flags->conv);
	if (n == 0)
		return ((ctoa(va_arg(ap, int))));
	if (n == 1)
		return ((atoa(va_arg(ap, char *))));
	if (n == 2)
		return ((ptoa((void*)va_arg(ap, unsigned long long))));
	if (n == 3)
		return ((ft_itoa(va_arg(ap, int))));
	if (n == 4)
		return ((ft_itoa(va_arg(ap, int))));
	if (n == 5)
		return ((ft_itoa(va_arg(ap, unsigned int))));
	if (n == 6)
		return ((xtoa(va_arg(ap, unsigned int))));
	if (n == 7)
		return ((x_majtoa(va_arg(ap, unsigned int))));
	if (n == 8)
		return (ctoa('%'));
	return (0);
}

char		*prec_n_change(char *conv, long prec, int i)
{
	char	*new;
	char	*convcpy;
	int		size;
	int		neg;

	convcpy = conv;
	neg = 0;
	if (conv[0] == '-')
		neg = 1;
	size = ft_strlen(conv) - neg;
	if (prec <= size)
		return (conv);
	conv += neg;
	if (!(new = malloc(sizeof(char) * (prec + neg + 1))))
		return (NULL);
	new[prec + neg] = 0;
	if (neg)
		new[i++] = '-';
	while (prec-- - (size))
		new[i++] = '0';
	while (size-- >= 0)
		new[i++] = *conv++;
	free(convcpy);
	return (new);
}

int			printer(char *conv, t_flag *flags)
{
	if (flags->conv == 'x' || flags->conv == 'X' || flags->conv == 'u')
		return (x_printer(conv, flags));
	if (flags->conv == 'd' || flags->conv == 'i')
		return (n_printer(conv, flags));
	else
		return (spc_printer(conv, flags));
}

int			conv_init(char *data, va_list ap, int *i)
{
	int			j;
	t_flag		*flags;
	char		*conv;

	j = 0;
	if (!(flags = malloc(sizeof(t_flag))))
		return (-1);
	flags = init_flags(flags);
	while (data[j] && (checkf(data[j]) ||
	(ft_atoi(&data[j]) && (!flags->width || flags->precision == 0))))
	{
		flags = simple_flag(&data[j], flags, ap, &j);
		flags = harder_flag(&data[j], flags, &j);
	}
	if (!checksc(data[j]))
		return (j);
	else
		flags->conv = data[j++];
	conv = converter(flags, ap);
	*i += printer(conv, flags);
	free(flags);
	return (j);
}
