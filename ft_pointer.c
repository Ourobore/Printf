/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 08:58:45 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 11:00:34 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(t_flags f, t_type t)
{
	int			i;
	long int	len_int;

	i = 0;
	len_int = 0;
	len_int = get_length_int_base((long int)t.p, "0123456789abcdef", &len_int);
	i = 0;
	if (f.left)
	{
		write(1, "0x", 2);
		ft_putnbr_base_fd((long int)t.p, 1, "0123456789abcdef");
		while (i++ < f.width - 2 - len_int)
			write(1, " ", 1);
	}
	else
	{
		while (i++ < f.width - 2 - len_int)
			write(1, " ", 1);
		write(1, "0x", 2);
		ft_putnbr_base_fd((long int)t.p, 1, "0123456789abcdef");
	}
	g_nb_carac += len_int + i + 1;
}
