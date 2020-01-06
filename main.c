/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:09:05 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 08:49:22 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	long int i;
	i = 0; 
	printf("==== REAL =====\n");
	printf("%d\n", printf("|%010.10d|\n", -700000));
	printf("%d\n", ft_printf("|%010.10d|\n", -700000));
	//printf("[%ld]\n", get_length_int_base(-700000, "0123456789", &i));
	//ft_putnbr_base_fd(0xfafa, "0123456789abcdef", 1);
	printf("==== MINE =====\n");
	//system("leaks a.out");
}