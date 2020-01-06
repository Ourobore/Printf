/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 08:58:43 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 11:03:07 by lchapren         ###   ########.fr       */
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
	if (f.left)
		char_write_left(f, t, &i);
	else
		char_write_right(f, t, &i);
	g_nb_carac += i + 1;
}
