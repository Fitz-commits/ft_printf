
#include <stdlib.h>
#include "ft_printf.h"

t_list		*divide(const char *s)
{
	t_list *list;
	t_list *begin;
	unsigned int i;
	unsigned int k;

	i = 0;
	k = -1;
	while (s[++k + i])
	{
		k = 0;
		if(s)
			while (s[k + i])
				if (s[k++ + i] == '%' && s[k + i] && s[k + i] != '%')
					break;
		if (!list)
			begin = list = ft_lstnew(ft_strdndup(&s[i], k));
		else 
			list->next = ft_lstnew(ft_strdndup(&s[i], k));
		begin = list;
		while(s[i] && checkf(s[i]))
			i++;
		if(!checksc(s[i]))
			return (NULL);
		list->next = ft_lstnew(ft_strdndup(s, i));
		i += k;
	}
	return (begin);
}
