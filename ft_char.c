/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 08:58:43 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/17 13:18:01 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_percent(t_flags f)
{
	int i;

	i = 0;
	if (f.error)
		g_nb_carac = -1;
	else
	{
		if (f.left)
		{
			write(1, "%", 1);
			while (i < f.width - 1)
			{
				write(1, " ", 1);
				i++;
			}
		}
		else
		{
			if (f.fill)
				while (i < f.width - 1)
				{
					write(1, "0", 1);
					i++;
				}
			else
				while (i < f.width - 1)
				{
					write(1, " ", 1);
					i++;
				}
			write(1, "%", 1);
		}
		g_nb_carac = i + 1;
	}
}

void	ft_char(t_flags f, t_type t)
{
	int i;

	i = 0;
	if (f.error || f.fill || f.precision != -1)
		g_nb_carac = -1;
	else
	{
		if (f.left)
		{
			write(1, &(t.c), 1);
			while (i < f.width - 1)
			{
				write(1, " ", 1);
				i++;
			}
		}
		else
		{
			while (i < f.width - 1)
			{
				write(1, " ", 1);
				i++;
			}
			write(1, &t.c, 1);
		}
		g_nb_carac = i + 1;
	}
}
