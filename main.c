/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:09:05 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/31 15:41:19 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	printf("==== REAL =====\n");
	printf("%d\n", printf("|%x|\n", -700));
	//printf("%d\n", ft_printf("|%-.0x|\n", -10));
	printf("::%s::\n", convert_int_to_base(-700, "0123456789abcdef"));
	//ft_putnbr_base_fd(0xfafa, "0123456789abcdef", 1);
	printf("==== MINE =====\n");
	//system("leaks a.out");
}