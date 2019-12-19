/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:09:12 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/19 14:53:50 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*

int		string_total_length(f_flags f, t_type t)
{
	if (f.precision == -1)
		return (ft_strlen(t.s) >= f.width ? ft_strlen(t.s) : f.width);
	if (f.precision >= f.width && f.precision != -1)
		return (f.precision);
	else
		return (f.width);
}

void	string_write_left(t_flags f, t_type t)
{
	int length;

	length = string_total_length(f, t);
}

void	ft_string(t_flags f, t_type t)
{
	if (f.error || f.fill)
		g_nb_carac = -1;
	else
	{
		if (f.left)
			string_write_left();
		else
			string_write_right();
	}
}
*/
//Precision tronque si trop petit