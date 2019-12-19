/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:31:31 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/19 10:08:03 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_length_int(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		get_length(char *formula)
{
	int i;

	i = 0;
	while (formula[i] >= '0' && formula[i] <= '9')
		i++;
	return (i);
}

int		check_formulas(const char *s)
{
	t_flags	f;
	char	*formula;
	int		start;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			start = i;
			i += 1;
			while (is_conv(s, i) == -1 && s[i])
				i += 1;
			formula = ft_substr(s, start, (i - start) + 1);
			i++;
			f = ft_init_flags();
			f = get_flags(formula, f);
			if (f.error == 1)
				return (-1);
		}
		else
			i++;
	}
	return (1);
}
