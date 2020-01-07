/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:31:31 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/07 15:38:14 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	get_length_int_base(long int nbr, char *base, long int *i)
{
	int	length_base;

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

int		get_length_formula(char *formula)
{
	int i;

	i = 0;
	while (formula[i] >= '0' && formula[i] <= '9')
		i++;
	return (i);
}

int		check_flags(t_flags *f, char c)
{
	int r;

	r = 1;
	if (f->error == 1)
		r = -1;
	if (c == 'c' && (f->fill || f->precision > 0))
		r = -1;
	else if (c == 's' && f->fill)
		r = -1;
	else if (c == 'p' && (f->fill))
		r = -1;
	else if ((c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X') &&
			(f->left && f->fill && !f->star))
		f->fill = 0;
	return (r);
}

int		check_formulas(const char *s, va_list *va)
{
	t_flags	f;
	char	*formula;
	char	c;
	int		start;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			start = i++;
			while (is_conv(s, i) == -1 && s[i])
				i += 1;
			formula = ft_substr(s, start, (i - start) + 1);
			c = s[i++];
			f = ft_init_flags();
			f = get_flags(formula, f, &(*va));
			if (check_flags(&f, c) != 1)
				return (-1);
		}
		else
			i++;
	}
	return (1);
}

void			ft_putnbr_base_fd(long int nbr, int fd, char *base)
{
	long int		nbl;
	unsigned int	longueur_b;
	unsigned int	i;

	i = 0;
	nbl = nbr;
	longueur_b = ft_strlen(base);
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = nbl * -1;
	}
	if (nbl >= 0 && nbl <= longueur_b - 1)
		ft_putchar_fd(base[nbl], fd);
	else
	{
		ft_putnbr_base_fd(nbl / longueur_b, fd, base);
		ft_putchar_fd(base[(nbl % longueur_b)], fd);
	}
}
