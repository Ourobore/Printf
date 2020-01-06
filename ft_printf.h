/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:03:08 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 10:20:17 by lchapren         ###   ########.fr       */
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
	long int	u;
}				t_type;

int				ft_printf(const char *s, ...);
void			ft_parse(const char *s, va_list *va);
void			ft_convert(const char *s, int *i, va_list *va);
void			ft_call(char c, t_flags f, t_type t);
t_type			ft_init_type(void);
t_flags			ft_init_flags(void);
t_flags			get_flags(char *formula, t_flags f, va_list *va);
int				get_length_formula(char *formula);
int				get_length_int(long int n);
int				is_conv(const char *s, int i);
int				check_formulas(const char *s, va_list *va);

void			ft_char(t_flags f, t_type t);
void			ft_percent(t_flags f);
void			ft_integer(t_flags f, t_type t, char *base);
void			ft_string(t_flags f, t_type t);
void			ft_unsigned_integer(t_flags f, t_type t);
void			ft_unsigned(t_flags f, t_type t, char *base);
void			ft_pointer(t_flags f, t_type t);

char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_calloc(size_t count, size_t size);
int				ft_strlen(char *s);
int				ft_atoi(const char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_base_fd(long int nbr, int fd, char *base);
long int		get_length_int_base(long int nbr, char *base, long int *i);
char			*convert_int_to_base(long int nbr, char *base);

#endif
