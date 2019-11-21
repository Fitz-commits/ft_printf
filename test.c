#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
/*
void ft_lol(int *i)
{
	*i += 1;
}
*/
/*char	*prec_n_change(char *conv, long prec, int i)
{
	char	*new;
	char	*convcpy;
	int size;
	int neg;

	convcpy = conv;
	neg = 0;
	if (conv[0] == '-')
		neg = 1;
	conv += neg;
	size = ft_strlen(conv) - neg;
	if(prec <= size)
		return (conv);
	if(!(new = malloc(sizeof(char) * (prec + neg))))
		return (NULL);
	new[prec + neg] = 0;
	if(neg)
		new[i++] = '-';
	while(prec-- - (size + neg))
		new[i++] = '0';
	while(size-- >= 0)
			new[i++] = *conv++;
	free(convcpy);
	return (new);
}
*/
/*
int		main()

{
	char *yo;
	int c;
	void *ptr;
	char *lo;

	c = 2555;
	//int i = 1;
	//ft_lol(&i);
	//printf("%llu\n", (unsigned long long)(ptr));
	//printf("%p\n", ptr);
	//yo = ft_strdup("899");
	//yo = prec_n_change(yo, 7, 0);
	printf("|%010p|", "sakyt");
	//free(yo);
}


int		main()
{
	printf("%lu", strlen("                                       "));
}
*/