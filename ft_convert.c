/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:07:24 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/31 09:00:51 by lchapren         ###   ########.fr       */
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
	t_type	t;

	t = ft_init_type();
	if (c == 'c')
		t.c = va_arg(*va, int);
	else if (c == 's')
		t.s = va_arg(*va, char*);
	else if (c == 'p')
		t.p = va_arg(*va, void*);
	else if (c == 'd' || c == 'i')
		t.i = va_arg(*va, int);
	else if (c == 'u' || c == 'x' || c == 'X')
		t.u = va_arg(*va, int);
	return (t);
}

void	ft_call(char c, t_flags f, t_type t)
{
	if (c == 'c')
		ft_char(f, t);
	else if (c == 's')
		ft_string(f, t);
	/*else if (c == 'p')
		ft_pointer(formula, &va);*/
	else if (c == '%')
		ft_percent(f);
	else if (c == 'd' || c == 'i')
		ft_integer(f, t, "0123456789");
	else if (c == 'u')
		ft_unsigned_integer(f, t);
	else if (c == 'x')
		ft_unsigned(f, t, "0123456789abcdef");
	else if (c == 'X')
		ft_unsigned(f, t, "0123456789ABCDEF");
}

void	ft_convert(const char *s, int *i, va_list *va)
{
	t_flags	f;
	t_type	t;
	char	*formula;
	char	c;
	int		start;

	start = *i;
	*i += 1;
	while (is_conv(s, *i) == -1 && s[*i])
		*i += 1;
	c = s[*i];
	formula = ft_substr(s, start, (*i - start) + 1);
	//*i += 1;
	f = ft_init_flags();
	f = get_flags(formula, f, &(*va));
	if (f.error == 1)
		return ;
	t = get_type(c, &(*va));
	ft_call(c, f, t);
	free(formula);
}
