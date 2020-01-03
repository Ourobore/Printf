/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:53:21 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/03 16:56:13 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			integer_total_length(t_flags f, long int len_int)
{
	if (len_int > f.width && len_int > f.precision)
		return (len_int);
	else if (f.precision >= len_int && f.precision >= f.width)
		return (f.precision);
	else if (f.width >= len_int && f.width >= f.precision)
		return (f.width);
	else
		return (-1);
}

void		integer_write_left(t_flags f, t_type t, char *base)
{
	int			i;
	int			length;
	long int	len_int;

	i = 0;
	len_int = 0;
	len_int = get_length_int_base(t.i, base, &len_int);
	length = integer_total_length(f, len_int);
	g_nb_carac += length;
	if (t.i < 0)
	{
		write(1, "-", 1);
		t.i *= -1;
	}
	if (f.precision >= f.width && f.precision > len_int)
		while (i < f.precision -
			(f.width && f.width < len_int ? f.width : len_int))
		{
			write(1, "0", 1);
			i++;
		}
	else if (f.precision < f.width && f.precision > len_int)
		while (i <= (f.width - f.precision))
		{
			write(1, "0", 1);
			i++;
		}
	ft_putnbr_base_fd(t.i, 1, base);
	i += len_int;
	while (i++ < length)
		write(1, " ", 1);
}

void		integer_write_right(t_flags f, t_type t, char *base)
{
	int			i;
	int			length;
	long int	len_int;

	i = 0;
	len_int = 0;
	len_int = get_length_int_base(t.i, base, &len_int);
	length = integer_total_length(f, len_int);
	g_nb_carac += length;
	while (i < length - (len_int > f.precision ? len_int : f.precision))
	{
		write(1, " ", 1);
		i++;
	}
	if (t.i < 0)
	{
		write(1, "-", 1);
		t.i *= -1;
	}
	while (i++ < length - len_int)
		write(1, "0", 1);
	ft_putnbr_base_fd(t.i, 1, base);
}

void		integer_write_fill(t_flags f, t_type t, char *base)
{
	int			i;
	int			length;
	long int	len_int;

	i = 0;
	len_int = 0;
	len_int = get_length_int_base(t.i, base, &len_int);
	length = integer_total_length(f, len_int);
	g_nb_carac += length;
	while (i < f.precision - len_int - 1 &&
		f.precision != -1 && f.width > f.precision)
	{
		write(1, " ", 1);
		i++;
	}
	if (t.i < 0)
	{
		write(1, "-", 1);
		t.i *= -1;
	}
	while (i++ < length - len_int)
		write(1, "0", 1);
	ft_putnbr_base_fd(t.i, 1, base);
}

void		ft_integer(t_flags f, t_type t, char *base)
{
	if (f.error || (f.left && f.fill))
		g_nb_carac = -1;
	else
	{
		if (t.i == 0 && f.precision == 0)
			return ;
		if (t.i < 0)
			f.precision++;
		if (f.left)
			integer_write_left(f, t, base);
		else if (f.fill)
			integer_write_fill(f, t, base);
		else
			integer_write_right(f, t, base);
	}
}
// Right et Left sont bon
//%010.d ne marche pas avec d neg, ainsi que 10.8 et 10. avec d pos