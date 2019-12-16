/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:03:08 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/16 11:17:27 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	g_return;

typedef struct	s_flags
{
	int		left;
	int		fill;
	int		precision;
	int		width;
	int		error;
}				t_flags;

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
	int				nb_carac;
}				t_conv;

int				ft_printf(const char *s, ...);
t_conv			ft_parse(char *s, t_conv conv);
t_flags			ft_init_flags();
t_conv			ft_init(t_conv elem);
void			ft_convert(char *s, int *i);
t_flags			get_flags(char *formula);
int				get_length(char *formula);

char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strlen(char *s);
int				ft_atoi(const char *s);
#endif
