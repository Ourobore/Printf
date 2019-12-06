/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:26:52 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/04 13:55:32 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_slash(char *s, int *i)
{
	if (s[i + 1] == 't')
		write(1, '\t', 1);
	else if (s[i + 1] == ' ')
		write(1, ' ', 1);
	else if (s[i + 1] == 'f')
		write(1, '\f', 1);
	else if (s[i + 1] == 'n')
		write(1, '\n', 1);
	else if (s[i + 1] == 'r')
		write(1, '\r', 1);
	else if (s[i + 1] == 'v')
		write(1, '\v', 1);
}

t_conv	ft_parse(char *s, t_conv conv)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\\')
			ft_slash(s, &i);
		else if (s[i] == '%')
			ft_conversion();
		else
			write(1, &s[i], 1);
		i++;
	}
	return (conv);
}
