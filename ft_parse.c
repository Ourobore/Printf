/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:26:52 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/10 11:10:38 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	ft_parse(char *s, t_conv conv)
{
	int i;

	i = 0;
	if (!s)
		return (conv);
	while (s[i])
	{
		if (s[i] == '%')
			ft_convert(s, conv, &i);
		else
			write(1, &s[i], 1);
		i++;
	}
	return (conv);
}
