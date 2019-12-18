/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:53:21 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/18 11:45:33 by lchapren         ###   ########.fr       */
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
		if (t.i == -2147483648)
			t.i = 2147483648;
		else
			t.i *= -1;
	}
	ft_putnbr_fd(t.i, 1);
	while (*i < length - len_int)
	{
		write(1, " ", 1);
		*i += 1;
	}
	g_nb_carac = length;
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
	}
}

//Precision == nb zero superpose et devant le nombre, si precision > width = agrandi
//Si int < 0 print - tout de suite