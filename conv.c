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
	if (ft_atoi(&data[0]) && !flags->width)
		{
			flags->width = ft_atoi(&data[0]);
			*j+= get_size(flags->width, 10) - 1;
		}
	if (ft_atoi(&data[0]) && !flags->precision)
	{
		flags->precision = ft_atoi(&data[0]);
		*j+= get_size(flags->precision, 10) - 1;
	}
	*j += 1;
	return (flags);
}

int conv_search(char c)
{
	int j;
	char *temp;

	j = 0;
	if(!(temp = ft_strdup("cspdiuxX")))
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

int		printer(t_flag *flags, va_list ap)
{
	int n;

	n = conv_search(flags->conv);
	if( n == 0)
		return (ft_putstr_fdi(ctoa(va_arg(ap, int)), 1));
	if( n == 1)
		return (ft_putstr_fdi(atoa(va_arg(ap, char *)), 1));
	if( n == 2)
		return (ft_putstr_fdi(ptoa((void*)va_arg(ap, unsigned long long)), 1));
	if( n == 3)
		return (ft_putstr_fdi(ft_itoa(va_arg(ap, int)), 1));
	if( n == 4)
		return (ft_putstr_fdi(ft_itoa(va_arg(ap, int)), 1));
	if( n == 5)
		return (ft_putstr_fdi(ft_itoa(va_arg(ap, unsigned int)), 1));
	if( n == 6)
		return (ft_putstr_fdi(xtoa(va_arg(ap, unsigned long long)), 1));
	if( n == 7)
		return (ft_putstr_fdi(x_majtoa(va_arg(ap, unsigned long long)), 1));
	return(0);
}
int	conv_init(char *data, va_list ap, int *i)
//i is the progression on the initial string that need 
//to be changed
{
	int j;
	t_flag *flags;

	j = 0;
	if(data[0] == '%')
		return (*i += write(1, &"%", 1));
	if(!(flags = malloc(sizeof(t_flag))))
		return -1;
	flags = init_flags(flags);
	while (data[j] && (checkf(data[j]) || (ft_atoi(&data[j]) && (!flags->width ||
		flags->precision == 0))))
		flags = simple_flag(&data[j], flags, ap, &j);
	if(!checksc(data[j]))
		return (-1);
	else
		flags->conv = data[j++];
	*i += printer(flags, ap);
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