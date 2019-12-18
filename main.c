/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:09:05 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/18 15:35:49 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	//t_flags f = ft_init_flags();
	printf("==== REAL =====\n");
	printf("|%2.5d|\n", 0);
	printf("%d\n", ft_printf("|%2.5d|\n", 0));
	//printf(":%d:\n", check_formulas("abc%-20c def %%%10c\n"));
	printf("==== MINE =====\n");
	//system("leaks a.out");
}