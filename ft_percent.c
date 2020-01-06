/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 07:47:41 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 11:04:18 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_write_left(t_flags f, int *i)
{
	write(1, "%", 1);
	while (*i < f.width - 1)
	{
		write(1, " ", 1);
		*i += 1;
	}
}

void	percent_write_right(t_flags f, int *i)
{
	if (f.fill)
		while (*i < f.width - 1)
		{
			write(1, "0", 1);
			*i += 1;
		}
	else
		while (*i < f.width - 1)
		{
			write(1, " ", 1);
			*i += 1;
		}
	write(1, "%", 1);
}

void	ft_percent(t_flags f)
{
	int i;

	i = 0;
	if (f.left)
		percent_write_left(f, &i);
	else
		percent_write_right(f, &i);
	g_nb_carac += i + 1;
}
