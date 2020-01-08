/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 08:58:45 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/08 11:27:46 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_write_left(t_flags f, t_type t, long int len_int)
{
	int i;

	i = 0;
	write(1, "0x", 2);
	ft_putnbr_base_fd((long int)t.p, 1, "0123456789abcdef");
	while (i++ < f.width - 2 - len_int)
		write(1, " ", 1);
	g_nb_carac += len_int + i + 1;
}

void	pointer_write_right(t_flags f, t_type t, long int len_int)
{
	int i;

	i = 0;
	while (i < f.width - 2 - len_int)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, "0x", 2);
	while (i++ < f.precision - len_int)
		write(1, "0", 1);
	ft_putnbr_base_fd((long int)t.p, 1, "0123456789abcdef");
	g_nb_carac += len_int + i + 1;
}

void	ft_pointer(t_flags f, t_type t)
{
	int			i;
	long int	len_int;

	i = 0;
	len_int = 0;
	len_int = get_length_int_base((long int)t.p, "0123456789abcdef", &len_int);
	if (t.p == 0 && f.precision != -1)
	{
		while (i < f.width - 2)
		{
			write(1, " ", 1);
			i++;
		}
		write(1, "0x", 2);
		g_nb_carac += 2;
		while (i++ < f.precision)
			write(1, "0", 1);
		g_nb_carac += i - 1;
	}
	else if (f.left)
		pointer_write_left(f, t, len_int);
	else
		pointer_write_right(f, t, len_int);
}
