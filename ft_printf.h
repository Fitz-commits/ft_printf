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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef	struct		s_flag
{
	int		width;
	int		precision;
	int		left_pad;
	int		zero_conv;
	char	conv;
}					t_flag;

int					ft_printf(const char *format, ...);
int					checkf(unsigned int c);
int					checksc(unsigned int c);
int					ft_putstr_fdi(char *s, int fd);
char				*ptoa(void *ptr);
char				*ctoa(int c);
char				*atoa(char *s);
char				*ft_itoa(long nbr);
char				*xtoa(unsigned long long nb);
char				*x_majtoa(unsigned long long nb);
int					get_size(long long nbr, int base);
char				*protoa(int c);
int					get_sizeu(unsigned long long nbr, int base);
t_flag				*init_flags(t_flag *flags);
t_flag				*harder_flag(char *data, t_flag *flags, int *j);
t_flag				*simple_flag(char *data, t_flag *flags, va_list ap, int *j);
t_flag				*wdt_spc_printer(int size, int *print, t_flag *flags);
int					conv_search(char c);
char				*converter(t_flag *flags, va_list ap);
int					numered(char c);
char				*prec_n_change(char *conv, long prec, int i);
char				*zwmod(char *conv, int *print, int *width);
int					n_printer(char *conv, t_flag *flags);
int					x_printer(char *conv, t_flag *flags);
int					spc_printer(char *conv, t_flag *flags);
int					printer(char *conv, t_flag *flags);
int					conv_init(char *data, va_list ap, int *i);

#endif
