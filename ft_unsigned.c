/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:50:36 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/03 11:07:11 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	get_length_int_base(long int nbr, char *base, long int *i)
{
	int	length_base;

	//if (nbr < 0)
	//	nbr *= -1;
	length_base = ft_strlen(base);
	if (nbr >= 0 && nbr <= length_base - 1)
		*i += 1;
	else
	{
		get_length_int_base(nbr / length_base, base, i);
		*i += 1;
	}
	return (*i);
}
/*
char		*convert_int_to_base(long int nbr, char *base)
{
	long int	i;
	int			rest;
	int			length_base;
	char		*s;

	i = 0;
	if (nbr < 0)
		nbr += 4294967296;
	length_base = ft_strlen(base);
	i = get_length_int_base(nbr, base, &i);
	s = ft_calloc(sizeof(char), i + 1);
	if (nbr == 0)
		s[0] = '0';
	while (nbr != 0)
	{
		i--;
		rest = nbr % length_base;
		nbr = nbr / length_base;
		s[i] = base[rest];
	}
	return (s);
}
*/
void		ft_unsigned(t_flags f, t_type t, char *base)
{
	if (t.u < 0)
		t.i = 4294967296 + t.u;
	else
		t.i = t.u;
	ft_integer(f, t, base);
}


/*
1 - Si nombre est negatif, soustraire a L_INT_MAX
2 - Conversion en hexa
3 - Calcul taille prise en hexa -> appel de fonction dans ft_integer
4 - Appel ft_integer
*/