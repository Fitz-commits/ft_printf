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



int		ft_printf(const char *format, ...);
int		checkf(unsigned int c);
int		checksc(unsigned int c);

typedef	struct		s_flag
{
	int		width;
	int		precision;
	int		left_pad;
	int		zero_conv;
	char	conv;
}					t_flag;

