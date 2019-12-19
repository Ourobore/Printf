/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:26:52 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/19 14:42:07 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(const char *s, va_list *va)
{
	int i;

	i = 0;
	if (check_formulas(s) == -1)
		g_nb_carac = -1;
	else
	{
		while (s[i] && g_nb_carac != -1)
		{
			if (s[i] == '%')
				ft_convert(s, &i, va);
			else
			{
				write(1, &s[i], 1);
				g_nb_carac += 1;
			}
			i++;
		}
	}
}

t_flags	get_flags(char *formula, t_flags f)
{
	int i;

	i = 1;
	while (formula[i + 1])
	{
		if (formula[i] == '0' && !f.width && f.precision == -1)
			f.fill = 1;
		else if (formula[i] == '-' && !f.width && f.precision == -1)
			f.left = 1;
		else if (formula[i] == '.' && f.precision == -1)
		{
			f.precision = ft_atoi(formula + i + 1);
			i += get_length(formula + i + 1);
		}
		else if (formula[i] >= '1' && formula[i] <= '9' &&
					!f.width && f.precision == -1)
		{
			f.width = ft_atoi(formula + i);
			i += get_length(formula + i) - 1;
		}
		else
			f.error = 1;
		i++;
	}
	return (f);
}
