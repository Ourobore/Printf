/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:03:08 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/10 09:18:30 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_conv
{
	char			c;
	char			*s;
	char			*p;
	int				d;
	int				i;
	unsigned int	u;
	char			*minx;
	char			*majx;
	char			*percent;
	int				left;
	int				fill;
	int				precision;
	int				width;
}				t_conv;

int				ft_printf(const char *s, ...);
t_conv			ft_parse(char *s, t_conv conv);
t_conv			ft_init(t_conv elem);
void			ft_convert(char *s, t_conv conv, int *i);

#endif
