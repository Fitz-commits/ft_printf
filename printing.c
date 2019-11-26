/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:47:15 by cdelaby           #+#    #+#             */
/*   Updated: 2019/11/26 14:47:17 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*zwmod(char *conv, int *print, int *width)
{
	int		neg;
	char	*cpy;

	neg = 0;
	if (conv[0] == '-')
	{
		*width -= 1;
		*print += write(1, &"-", 1);
		neg = 1;
	}
	cpy = conv;
	conv = ft_strdup(&conv[neg]);
	free(cpy);
	return (conv);
}

int			n_printer(char *conv, t_flag *flags)
{
	int size;
	int print;

	print = 0;
	if (flags->width && flags->precision < 0 &&
	conv[0] == '-' && flags->zero_conv)
		conv = zwmod(conv, &print, &flags->width);
	if (flags->precision > 0)
		conv = prec_n_change(conv, flags->precision, 0);
	size = ft_strlen(conv);
	if ((flags->width > size && !flags->left_pad))
	{
		if (flags->precision <= -1 && flags->zero_conv)
			while (flags->width-- > size)
				print += write(1, &"0", 1);
		else
			while (flags->width-- > size)
				print += write(1, &" ", 1);
	}
	print += ft_putstr_fdi(conv, 1);
	if (flags->width > size && flags->left_pad)
		while (flags->width-- > size)
			print += write(1, &" ", 1);
	free(conv);
	return (print);
}

int			x_printer(char *conv, t_flag *flags)
{
	int		size;
	int		print;

	print = 0;
	if (flags->precision > 0)
		conv = prec_n_change(conv, flags->precision, 0);
	size = ft_strlen(conv);
	if ((flags->width > size && !flags->left_pad))
	{
		if ((flags->zero_conv && flags->precision <= -1))
			while (flags->width-- > size)
				print += write(1, &"0", 1);
		else
			while (flags->width-- > size)
				print += write(1, &" ", 1);
	}
	print += ft_putstr_fdi(conv, 1);
	if (flags->width > size && flags->left_pad)
		while (flags->width-- > size)
			print += write(1, &" ", 1);
	free(conv);
	return (print);
}

t_flag		*wdt_spc_printer(int size, int *print, t_flag *flags)
{
	if (flags->zero_conv)
		while (flags->width-- > size)
			*print += write(1, &"0", 1);
	else
		while (flags->width-- > size)
			*print += write(1, &" ", 1);
	return (flags);
}

int			spc_printer(char *conv, t_flag *flags)
{
	int size;
	int print;

	print = 0;
	if (flags->conv == 'c' && conv[0] == 0)
		flags->width--;
	if (flags->conv == 's' && flags->precision > -1 &&
	flags->precision < ft_strlen(conv))
		conv[flags->precision] = 0;
	size = ft_strlen(conv);
	if (flags->width > size && !flags->left_pad)
		flags = wdt_spc_printer(size, &print, flags);
	if (flags->conv == 'c' && conv[0] == 0)
		print += write(1, &"\0", 1);
	else
		print += ft_putstr_fdi(conv, 1);
	if (flags->width > size && flags->left_pad)
		while (flags->width-- > size)
			print += write(1, &" ", 1);
	free(conv);
	return (print);
}
