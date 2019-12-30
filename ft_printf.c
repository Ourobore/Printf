/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:28:16 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/30 09:35:45 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	va;

	g_nb_carac = 0;
	va_start(va, s);
	ft_parse(s, &va);
	va_end(va);
	return (g_nb_carac);
}
//Verif chaque formule avant d'imprimer char/int -> dans ft_call? ou check_formulas?
//Gerer le cas si les types ne correspondent pas -> ne doit pas seg fault
//Reste a gérer le retour de printf: faire un retour de longueur a la fin de chaine de fonction?
