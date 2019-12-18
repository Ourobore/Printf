/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:04:58 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/18 07:42:23 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	f;

	f.left = 0;
	f.fill = 0;
	f.precision = -1;
	f.width = 0;
	f.error = 0;
	return (f);
}

t_type	ft_init_type(void)
{
	t_type	t;

	t.i = 0;
	t.c = 0;
	t.s = 0;
	t.p = 0;
	t.u = 0;
	return (t);
}
