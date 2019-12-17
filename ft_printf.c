/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:28:16 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/17 13:06:22 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_flags	f;
	va_list	va;

	g_nb_carac = 0;
	va_start(va, s);
	ft_parse(s, &f, &va);
	va_end(va);
	return (g_nb_carac);
}

//Reste a gérer le retour de printf: faire un retour de longueur a la fin de chaine de fonction?
