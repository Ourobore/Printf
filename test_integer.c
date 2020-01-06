/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 15:54:25 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/31 15:55:49 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			integer_total_length(t_flags f, int len_int)
{
	if (len_int >= f.width && len_int >= f.precision)
		return (len_int);
	else if (f.width >= len_int && f.width >= f.precision)
		return (f.width);
	else if (f.precision >= len_int && f.precision >= f.width)
		return (f.precision);
	else
		return (-1);
}

void		integer_write_left(t_flags f, t_type t, char *base)
{
	int length;
	int len_int;

	len_int = get_length_int(t.i, base, 0);
	length = integer_total_length(f, len_int);
	g_nb_carac += length;
	if (t.i < 0)
	{
		write(1, "-", 1);
		t.i *= -1;
		length--;
	}
	while (length-- - len_int > 0)
		write(1, "0", 1);
	ft_putnbr_base_fd(t.i, 1, base);
	while (length-- > ((len_int >= f.precision) ? len_int : f.precision))
		write(1, " ", 1);
}

void		integer_write_right(t_flags f, t_type t, char *base)
{
	int length;
	int len_int;

	len_int = get_length_int_base(t.i, base, 0);
	length = integer_total_length(f, len_int);
	g_nb_carac += length;
	if (t.i < 0)
		length--;
	while (length-- > ((len_int >= f.precision) ? len_int : f.precision))
		write(1, " ", 1);
	if (t.i < 0)
	{
		write(1, "-", 1);
		if (f.precision >= f.width)
			g_nb_carac++;
		t.i *= -1;
	}
	while (f.precision-- - len_int > 0)
		write(1, "0", 1);
	ft_putnbr_base_fd(t.i, 1, base);
}

void		ft_integer(t_flags f, t_type t, char *base)
{
	int i;

	i = 0;
	if (f.error || (f.left && f.fill))
		g_nb_carac = -1;
	else
	{
		if (t.i == 0 && f.precision == 0)
			return ;
		else if (f.left)
			integer_write_left(f, t, base);
		else
			integer_write_right(f, t, base);
	}
}