/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 08:58:43 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/30 08:49:42 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_write_left(t_flags f, t_type t, int *i)
{
	write(1, &(t.c), 1);
	while (*i < f.width - 1)
	{
		write(1, " ", 1);
		*i += 1;
	}
}

void	char_write_right(t_flags f, t_type t, int *i)
{
	while (*i < f.width - 1)
	{
		write(1, " ", 1);
		*i += 1;
	}
	write(1, &t.c, 1);
}

void	ft_char(t_flags f, t_type t)
{
	int i;

	i = 0;
	if (f.error || f.fill || f.precision > 0)
		g_nb_carac = -1;
	else
	{
		if (f.left)
			char_write_left(f, t, &i);
		else
			char_write_right(f, t, &i);
		g_nb_carac += i + 1;
	}
}
