/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:09:05 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/16 11:35:59 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	//t_conv	elem;
	//elem = ft_init(elem);
	//printf("\n==== MINE =====\n");
	//ft_parse("abc%asddtd%hjvcef%%", elem);
	printf("==== REAL =====\n");
	printf("|%010d|\n", 11);
	printf("%d\n", get_flags("%010.000d").width);
}