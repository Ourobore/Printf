/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:09:05 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 13:44:28 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	char *i = NULL;
	i = malloc(5);
	printf("==== REAL =====\n");
	printf("%d\n", printf("|%016.d|\n", 00000));
	printf("%d\n", ft_printf("|%016.d|\n", 00000));
	//printf("[%ld]\n", get_length_int_base(-700000, "0123456789", &i));
	//ft_putnbr_base_fd(**p, 1, "0123456789abcdef");
	printf("==== MINE =====\n");
	//system("leaks a.out");
}