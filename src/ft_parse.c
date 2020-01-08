/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:26:52 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/08 11:24:42 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(const char *s, va_list *va)
{
	va_list	verif;
	int		i;

	va_copy(verif, *va);
	i = 0;
	if (check_formulas(s, &verif) == -1)
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

t_flags	get_star(char *formula, t_flags f, va_list *va, int *i)
{
	if (formula[*i - 1] == '.')
	{
		f.precision = va_arg(*va, int);
		if (f.precision < 0)
			f.precision = -1;
	}
	else if (!f.width)
	{
		f.width = va_arg(*va, int);
		if (f.width < 0)
		{
			f.width *= -1;
			f.left = 1;
			f.star = 1;
		}
	}
	return (f);
}

t_flags	get_precision(char *formula, t_flags f, int *i)
{
	f.precision = ft_atoi((const char*)(formula + *i + 1));
	*i += get_length_formula(formula + *i + 1);
	return (f);
}

t_flags	get_width(char *formula, t_flags f, int *i)
{
	f.width = ft_atoi((const char*)(formula + *i));
	*i += get_length_formula(formula + *i) - 1;
	return (f);
}

t_flags	get_flags(char *formula, t_flags f, va_list *va)
{
	int i;

	i = 1;
	while (formula[i + 1])
	{
		if (formula[i] == '0' && !f.width && f.precision == -1)
			f.fill = 1;
		else if (formula[i] == '-' && !f.width && f.precision == -1)
			f.left = 1;
		else if (formula[i] == '*')
			f = get_star(formula, f, va, &i);
		else if (formula[i] == '.' && f.precision == -1)
			f = get_precision(formula, f, &i);
		else if (formula[i] >= '1' && formula[i] <= '9' &&
				!f.width && f.precision == -1)
			f = get_width(formula, f, &i);
		else
			f.error = 1;
		i++;
	}
	return (f);
}
