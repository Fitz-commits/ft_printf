
#include <stdlib.h>
#include "ft_printf.h"

t_list		divide(const char *format)
{
	t_list *list;
	t_list *begin;
	unsigned int i;
	unsigned

	i = 0;
	if(format)
			while (format[i] != '%')
				i++;
	list = ft_lstnew(ft_strdndup(format, i));
	begin = list;
	while(format[i])
	{
		if (format[i])
		{
			/* code */
		}
		
	}
	return (*begin);
}
