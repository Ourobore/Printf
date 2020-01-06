/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:50:36 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 10:33:12 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_unsigned(t_flags f, t_type t, char *base)
{
	if (t.u < 0)
		t.i = 4294967296 + t.u;
	else
		t.i = t.u;
	ft_integer(f, t, base);
}
