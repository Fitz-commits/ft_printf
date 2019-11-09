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
	return (flags);
}
int				get_size(int nbr)
{
	int i;

	i = 1;
	while (nbr / 10)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}
int	conv_init(char *data, va_list ap, int *i)
//i is the progression on the initial string that need 
//to be changed
//
//this function return a count of how many character it writes
//
{
	int j;
	t_flag *flags;

	j = 0;
	if(data[0] == '%')
		return ( *i += write(1, &"%", 1));
	if(!(flags = malloc(sizeof(t_flag))))
		return -1;
	flags = init_flags(flags);
	while (data[j] && (checkf(data[j]) || (ft_atoi(&data[j]) && (!flags->width ||
		flags->precision == 0))))
	{
		if (data[j] == '0')
			flags->zero_conv = 1;
		if (data[j] == '-')
			flags->left_pad = 1;
		if (ft_atoi(&data[j]) && !flags->width)
		{
			flags->width = ft_atoi(&data[j]);
			j+= get_size(flags->width);
			continue;
		}
		if(flags->precision == -1 && data[j] == '*')
			flags->width = va_arg(ap, int);
		if(data[j] == '.')
			flags->precision = 0;
		if (ft_atoi(&data[j]) && !flags->precision)
		{
			flags->precision = ft_atoi(&data[j]);
			j+= get_size(flags->precision);
			continue;
		}
		if (flags->precision == 0 && data[j] == '*')
			flags->precision = va_arg(ap, int);
	}
	if()
	*i += 1;
	printf(" %d\n %d\n %d\n %d\n",flags->width, flags->precision, flags->left_pad, flags-> zero_conv);
	return j;
}

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
	test("*-.*s", 7, 8);
}