/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:09:12 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/31 13:23:39 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_total_length(t_flags f, t_type t)
{
	if (f.precision == -1)
		return (ft_strlen(t.s) >= f.width ? ft_strlen(t.s) : f.width);
	else if (f.precision >= f.width && f.precision != -1)
		return (f.precision);
	else
		return (f.width);
}

void	string_write_left(t_flags f, t_type t)
{
	int i;
	int length;

	i = 0;
	length = string_total_length(f, t);
	while (t.s[i] && i < length)
	{
		write(1, &(t.s[i]), 1);
		i++;
	}
	while (i < length)
	{
		write(1, " ", 1);
		i++;
	}
	g_nb_carac += i;
}

void	string_write_right(t_flags f, t_type t)
{
	int i;
	int length;
	int l;

	i = 0;
	length = string_total_length(f, t);
	l = ft_strlen(t.s);
	while (i < length - l)
	{
		write(1, " ", 1);
		i++;
	}
	g_nb_carac += i;
	i = 0;
	while (t.s[i] && i < length)
	{
		write(1, &(t.s[i]), 1);
		i++;
	}
	g_nb_carac += i;
}

void	ft_string(t_flags f, t_type t)
{
	if (f.error || f.fill)
		g_nb_carac = -1;
	else
	{
		if (f.left)
			string_write_left(f, t);
		else
			string_write_right(f, t);
	}
}
