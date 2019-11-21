/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:37:11 by cdelaby           #+#    #+#             */
/*   Updated: 2019/10/26 12:37:13 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
#include <unistd.h>



int		ft_printf(const char *format, ...);
int		checkf(unsigned int c);
int		checksc(unsigned int c);
int		ft_putstr_fdi(char *s, int fd);
char	*ptoa(void *ptr);
char 	*ctoa(int c);
char 	*atoa(char *s);
char 	*xtoa(unsigned long long nb);
char 	*x_majtoa(unsigned long long nb);
int		get_size(long long nbr, int base);
char	*protoa(int c);
int		get_sizeu(unsigned long long nbr, int base);


//(*funct_ptr[8]) = {*ctoa, *atoa, *ptoa, *ft_itoa, *ft_itoa, *ft_itoa, *xtoa, *x_majtoa};

typedef	struct		s_flag
{
	int		width;
	int		precision;
	int		left_pad;
	int		zero_conv;
	char	conv;
}					t_flag;

t_flag		*init_flags(t_flag *flags);
t_flag		*simple_flag(char *data, t_flag *flags, va_list ap, int *j);
int 		conv_search(char c);
char		*converter(t_flag *flags, va_list ap);
int			conv_init(char *data, va_list ap, int *i);

