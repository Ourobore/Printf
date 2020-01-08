/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:09:12 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/08 09:59:15 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_total_length(t_flags f, int l)
{
	if (f.precision == -1)
		return (l >= f.width ? l : f.width);
	else if (f.precision > f.width)
	{
		if (l > f.width)
			return ((f.precision > l ? l : f.precision));
		else
			return (f.width);
	}
	else
		return (f.width);
}

void	string_write_left(t_flags f, t_type t)
{
	int i;
	int l;
	int length;

	i = 0;
	l = ft_strlen(t.s);
	length = string_total_length(f, l);
	while (t.s[i] && i < (f.precision != -1 ? f.precision : l))
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
	int l;
	int	space;
	int length;

	i = 0;
	l = ft_strlen(t.s);
	length = string_total_length(f, l);
	if (f.precision < l && f.precision != -1)
		space = f.precision;
	else
		space = l;
	while (i < f.width - space)
	{
		write(1, " ", 1);
		i++;
	}
	g_nb_carac += i;
	i = 0;
	while (t.s[i] && i < (f.precision != -1 ? f.precision : l))
	{
		write(1, &(t.s[i]), 1);
		i++;
	}
	g_nb_carac += i;
}

void	string_write_fill(t_flags f, t_type t)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(t.s);
	while (i < f.width - l)
	{
		write(1, "0", 1);
		i++;
	}
	g_nb_carac += i;
	i = 0;
	while (i < l)
	{
		write(1, &(t.s[i]), 1);
		i++;
	}
	g_nb_carac += i;
}

void	ft_string(t_flags f, t_type t)
{
	int n;

	n = 0;
	if (t.s == NULL)
	{
		t.s = ft_strdup("(null)");
		n = 1;
	}
	if (f.fill && !f.left)
		string_write_fill(f, t);
	else if (f.left)
		string_write_left(f, t);
	else
		string_write_right(f, t);
	if (n == 1)
		free(t.s);
}
