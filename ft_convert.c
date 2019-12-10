/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:07:24 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/10 09:57:29 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conv(char *s, int i)
{
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' ||
		s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X' ||
		s[i] == '%')
		return (1);
	else
		return (-1);
}

void	ft_call(char *formula, char c)
{
	if (c == 'c')
		ft_char();
	else if (c == 's')
		ft_string();
	else if (c == 'p')
		ft_pointer();
	else if (c == '%')
		ft_percent();
	else if (c == 'd' || c == 'i')
		ft_integer();
	else if (c == 'u' || c == 'x' || c == 'X')
		ft_unsigned();
}

void	ft_convert(char *s, t_conv conv, int *i)
{
	char	*formula;
	char	c;
	int		start;

	start = *i;
	*i++;
	while (is_conv(s, i) == -1 && s[*i])
		*i++;
	c = s[*i];
	formula = ft_substr(s, start, i - start);
	ft_call(formula, c);
}
