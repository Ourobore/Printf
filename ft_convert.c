/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:07:24 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/17 10:57:01 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conv(const char *s, int i)
{
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' ||
		s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X' ||
		s[i] == '%')
		return (1);
	else
		return (-1);
}

t_type	get_type(char c, va_list *va)
{
	t_type	ret;

	ret = ft_init_type();
	if (c == 'c')
		ret.c = va_arg(*va, int);
	else if (c == 's')
		ret.s = va_arg(*va, char*);
	else if (c == 'p')
		ret.p = va_arg(*va, void*);
	else if (c == 'd' || c == 'i')
		ret.i = va_arg(*va, int);
	else if (c == 'u' || c == 'x' || c == 'X')
		ret.u = va_arg(*va, int);
	return (ret);
}

/*

void	ft_call(char *formula, char c, t_flags *f, va_list *va)
{
	if (c == 'c')
		ft_char(formula, &va);
	else if (c == 's')
		ft_string(formula, &va);
	else if (c == 'p')
		ft_pointer(formula, &va);
	else if (c == '%')
		ft_percent(formula, &va);
	else if (c == 'd' || c == 'i')
		ft_integer(formula, &va);
	else if (c == 'u' || c == 'x' || c == 'X')
		ft_unsigned(formula, &va);
}

*/

void	ft_convert(const char *s, int *i, t_flags *f, va_list *va)
{
	t_type	t;
	char	*formula;
	char	c;
	int		start;

	start = *i;
	*i += 1;
	while (is_conv(s, *i) == -1 && s[*i])
		*i += 1;
	c = s[*i];
	t = get_type(c, &(*va));
	printf(":%c:", t.c);
	formula = ft_substr(s, start, (*i - start) + 1);
	*f = get_flags(formula, f);
	//ft_call(formula, c, &f, &va);
	free(formula);
}
