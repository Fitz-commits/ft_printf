/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:25:56 by cdelaby           #+#    #+#             */
/*   Updated: 2019/11/26 14:25:58 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			*init_flags(t_flag *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->left_pad = 0;
	flags->zero_conv = 0;
	flags->conv = 0;
	return (flags);
}

t_flag			*simple_flag(char *data, t_flag *flags, va_list ap, int *j)
{
	if (ft_atoi(&data[0]) > 0 && data[0] != '0')
		return (flags);
	if (data[0] == '0' && flags->precision == -1)
		flags->zero_conv = 1;
	if (data[0] == '-')
		flags->left_pad = 1;
	if (data[0] == '.')
		flags->precision = 0;
	if (flags->precision == -1 && flags->width == 0 && data[0] == '*')
		flags->width = va_arg(ap, int);
	if (flags->precision == 0 && data[0] == '*')
		flags->precision = va_arg(ap, int);
	if (flags->width < 0)
	{
		flags->left_pad = 1;
		flags->width = -flags->width;
	}
	*j += 1;
	return (flags);
}

t_flag			*harder_flag(char *data, t_flag *flags, int *j)
{
	if (ft_atoi(&data[0]) > 0 && !flags->width && flags->precision != 0
		&& data[0] != '0')
	{
		flags->width = ft_atoi(&data[0]);
		*j += get_size(flags->width, 10);
	}
	if (ft_atoi(&data[0]) > 0 && !flags->precision && data[0] != '0')
	{
		flags->precision = ft_atoi(&data[0]);
		*j += get_size(flags->precision, 10);
	}
	return (flags);
}
