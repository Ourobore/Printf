/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:31:31 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/03 15:09:13 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_length_int(long int n)
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

int		check_formulas(const char *s, va_list *va)
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
			f = get_flags(formula, f, &(*va));
			if (f.error == 1)
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