#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_flag		*init_flags(t_flag *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->left_pad = 0;
	flags-> zero_conv = 0;
	flags->conv = 0;
	return (flags);
}
t_flag		*simple_flag(char *data, t_flag *flags, va_list ap, int *j)
{
	if(ft_atoi(&data[0]) > 0 && data[0] != '0')
		return flags;
	if(data[0] == '0')
		flags->zero_conv = 1;
	if(data[0] == '-')
		flags->left_pad = 1;
	if(data[0] == '.')
		flags->precision = 0;
	if(flags->precision == -1 && flags->width == 0 && data[0] == '*')
		flags->width = va_arg(ap, int);
	if (flags->precision == 0 && data[0] == '*')
			flags->precision = va_arg(ap, int);
	if(flags->width < 0)
	{
		flags->left_pad = 1;
		flags->width = - flags->width;
	}
	*j += 1;
	return (flags);
}
t_flag		*harder_flag(char *data, t_flag *flags, int *j)
{
	if (ft_atoi(&data[0]) > 0 && !flags->width && flags->precision != 0
		&& data[0] != '0')
	{
		flags->width = ft_atoi(&data[0]);
		*j+= get_size(flags->width, 10);
	}
	if (ft_atoi(&data[0]) > 0 && !flags->precision && data[0] != '0')
	{
		flags->precision = ft_atoi(&data[0]);
		*j+= get_size(flags->precision, 10);
	}
	return (flags);
}


int conv_search(char c)
{
	int j;
	char *temp;

	j = 0;
	if(!(temp = ft_strdup("cspdiuxX%")))
		return (-1);
	while(temp[j])
	{
		if (temp[j] == c)
		{
			free(temp);
			return(j);
		}
		j++;
	}
	free(temp);
	return(j);
}

char 	*converter(t_flag *flags, va_list ap)
{
	int n;

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
		return ((xtoa(va_arg(ap, unsigned long long))));
	if (n == 7)
		return ((x_majtoa(va_arg(ap, unsigned long long))));
	if (n == 8)
		return (ctoa('%'));
	return(0);
}

int		numered(char c)
{
	if ( c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'u')
		return (1);
	else
		return (0);
	
}

char	*prec_n_change(char *conv, long prec, int i)
{
	char	*new;
	char	*convcpy;
	int size;
	int neg;

	convcpy = conv;
	neg = 0;
	if (conv[0] == '-')
		neg = 1;
	size = ft_strlen(conv) - neg;
	if(prec <= size)
		return (conv);
	conv += neg;
	if(!(new = malloc(sizeof(char) * (prec + neg))))
		return (NULL);
	new[prec + neg] = 0;
	if(neg)
		new[i++] = '-';
	while(prec-- - (size))
		new[i++] = '0';
	while(size-- >= 0)
			new[i++] = *conv++;
	free(convcpy);
	return (new);
}
int		n_printer(char *conv, t_flag *flags)
{
	int size;
	int print;

	print = 0;
	if(flags->precision > 0)
		conv = prec_n_change(conv,flags->precision, 0);
	size = ft_strlen(conv);
	if (flags->width > size && !flags->left_pad)
	{
		if(flags->zero_conv && flags->precision < -1)
		{
			while (flags->width-- > size)
				print += write(1, &"0",1);
		}
		else
		{
			while (flags->width-- > size)
				print += write(1, &" ", 1);
		}
	}
	print += ft_putstr_fdi(conv, 1);
	if (flags->width > size && flags->left_pad)
		while (flags->width-- > size)
			print += write(1, &" ", 1);
	return (print);
}

int		spc_printer(char *conv, t_flag *flags)
{
	int size;
	int print;

	print = 0;
	if(flags->conv == 's' && flags->precision != -1)
		conv[flags->precision] = 0;
	size = ft_strlen(conv);
	if (flags->width > size && !flags->left_pad)
	{
		if(flags->zero_conv)
			while (flags->width-- > size)
				print += write(1, &"0",1);
		else
			while (flags->width-- > size)
				print += write(1, &" ", 1);
	}
	print += ft_putstr_fdi(conv, 1);
	if (flags->width > size && flags->left_pad)
		while (flags->width-- > size)
			print += write(1, &" ", 1);
	return (print);
}
int		printer(char *conv, t_flag *flags)
{
	if (!conv)
		return(write(1, &"", 1));
	if (numered(flags->conv))
		return (n_printer(conv, flags));
	else
		return (spc_printer(conv, flags));
}

int	conv_init(char *data, va_list ap, int *i)
//i is the progression on the initial string that need 
//to be changed
{
	int j;
	t_flag *flags;
	char *conv;

	j = 0;
	if(!(flags = malloc(sizeof(t_flag))))
		return -1;
	flags = init_flags(flags);
	while (data[j] && (checkf(data[j]) || (ft_atoi(&data[j]) && (!flags->width ||
		flags->precision == 0))))
	{
		flags = simple_flag(&data[j], flags, ap, &j);
		flags = harder_flag(&data[j], flags, &j);
	}
	if(!checksc(data[j]))
		return (j);
	else
		flags->conv = data[j++];
	conv = converter(flags, ap);
	*i += printer(conv, flags);
	return j;
}

/*
int		test(char *format, ...)
{
	int i;
	va_list ap;
	va_start(ap, format);
	i = 0;
	conv_init(format, ap, &i);
	va_end(ap);
	return (i);
}

int main()
{
	test("0s");
}

*/