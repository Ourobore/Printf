/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:09:05 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/17 13:20:00 by lchapren         ###   ########.fr       */
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
	printf("|abc%-20c def|\n", 'z');
	printf("%d\n", ft_printf("|abc%-20c def|\n", 'z'));
	printf("==== MINE =====\n");
	//system("leaks a.out");
}