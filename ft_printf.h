/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:03:08 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/18 11:44:36 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	g_nb_carac;

typedef struct	s_flags
{
	int		left;
	int		fill;
	int		precision;
	int		width;
	int		error;
}				t_flags;

typedef struct	s_type
{
	long int	i;
	char		c;
	char		*s;
	void		*p;
	int			u;
}				t_type;

int				ft_printf(const char *s, ...);
void			ft_parse(const char *s, va_list *va);
void			ft_convert(const char *s, int *i, va_list *va);
void			ft_call(char c, t_flags f, t_type t);
t_type			ft_init_type(void);
t_flags			ft_init_flags(void);
t_flags			get_flags(char *formula, t_flags f);
int				get_length(char *formula);
int				get_length_int(int n);
int				is_conv(const char *s, int i);
int				check_formulas(const char *s);

void			ft_char(t_flags f, t_type t);
void			ft_percent(t_flags f);
void			ft_integer(t_flags f, t_type t);

char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strlen(char *s);
int				ft_atoi(const char *s);
void			ft_putnbr_fd(long int n, int fd);
#endif
