/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:04:58 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/10 08:13:12 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	ft_init(t_conv elem)
{
	elem.c = 0;
	elem.s = 0;
	elem.p = 0;
	elem.d = 0;
	elem.i = 0;
	elem.u = 0;
	elem.minx = 0;
	elem.majx = 0;
	elem.percent = 0;
	elem.left = 0;
	elem.fill = 0;
	elem.precision = 0;
	elem.width = 0;
	return (elem);
}
