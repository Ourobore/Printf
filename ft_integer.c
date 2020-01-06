/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:53:21 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 13:47:05 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		integer_write_left(t_flags f, t_type t, int sign, char *base)
{
	long int len_int;

	len_int = 0;
	len_int = get_length_int_base(t.i, base, &len_int);
	if (sign == 1)
	{
		write(1, "-", 1);
		g_nb_carac++;
	}
	while (f.precision > len_int)
	{
		write(1, "0", 1);
		f.precision--;
		f.width--;
		g_nb_carac++;
	}
	ft_putnbr_base_fd(t.i, 1, base);
	g_nb_carac += len_int;
	while (f.width > len_int + sign)
	{
		write(1, " ", 1);
		f.width--;
		g_nb_carac++;
	}
}

void		integer_write_right(t_flags f, t_type t, int sign, char *base)
{
	long int len_int;

	len_int = 0;
	len_int = get_length_int_base(t.i, base, &len_int);
	while (f.width > (f.precision > len_int ? f.precision : len_int) + sign &&
			f.precision != -1)
	{
		write(1, " ", 1);
		f.width--;
		g_nb_carac++;
	}
	if (sign == 1)
	{
		write(1, "-", 1);
		g_nb_carac++;
	}
	while ((f.width > f.precision ? f.width - sign : f.precision) > len_int)
	{
		write(1, "0", 1);
		f.width--;
		f.precision--;
		g_nb_carac++;
	}
	ft_putnbr_base_fd(t.i, 1, base);
	g_nb_carac += len_int;
}

void		ft_integer(t_flags f, t_type t, char *base)
{
	int	sign;

	sign = 0;
	if (t.i == 0 && f.precision == 0)
	{
		while (f.width)
		{
			write(1, " ", 1);
			f.width--;
			g_nb_carac++;
		}
		return ;
	}
	if (t.i < 0)
	{
		t.i *= -1;
		sign = 1;
	}
	if (f.left)
		integer_write_left(f, t, sign, base);
	else
		integer_write_right(f, t, sign, base);
}
