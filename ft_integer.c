/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:53:21 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/18 15:35:39 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		integer_write_left(t_flags f, t_type t, int *i)
{
	int length;
	int len_int;

	len_int = get_length_int(t.i);
	length = (f.width >= len_int) ? f.width : len_int;
	if (t.i < 0)
	{
		write(1, "-", 1);
		t.i *= -1;
	}
	if (t.i == 0)
		*i += 1;
	while (*i <= f.precision - len_int)
	{
		write(1, "0", 1);
		*i += 1;
	}
	ft_putnbr_fd(t.i, 1);
	while (*i < length - len_int)
	{
		write(1, " ", 1);
		*i += 1;
	}
	g_nb_carac = *i + len_int;
}

void		integer_write_right(t_flags f, t_type t, int *i)
{
	int length;
	int len_int;

	len_int = get_length_int(t.i);
	length = (f.width >= len_int) ? f.width : len_int;
	while (*i < length - f.precision - 1)
	{
		write(1, " ", 1);
		*i += 1;
	}
	if (t.i < 0)
	{
		write(1, "-", 1);
		t.i *= -1;
	}
	if (t.i == 0)
		*i += 1;
	*i = 0;
	while (*i <= f.precision - len_int)
	{
		write(1, "0", 1);
		*i += 1;
	}
	ft_putnbr_fd(t.i, 1);
	g_nb_carac = *i + length + len_int;
}

void		ft_integer(t_flags f, t_type t)
{
	int i;

	i = 0;
	if (f.error || (f.left && f.fill))
		g_nb_carac = -1;
	else
	{
		if (f.left)
			integer_write_left(f, t, &i);
		else
			integer_write_right(f, t, &i);
	}
}

//Retour faux avec precision