/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:09:05 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/30 11:11:31 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	//t_flags f = ft_init_flags();
	printf("==== REAL =====\n");
	printf("%d\n", printf("|%7.6u|\n", 10));
	printf("%d\n", ft_printf("|%7.6u|\n", 10));
	printf("==== MINE =====\n");
	//system("leaks a.out");
}