/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:32:23 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/07 09:51:48 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long int	i;
	unsigned long int	j;
	char				*cp;

	i = 0;
	j = start;
	if (!s || len == 0 || start > (unsigned int)ft_strlen((char*)s))
	{
		if (!(cp = ft_calloc(1, 1)))
			return (NULL);
		return (cp);
	}
	if (!(cp = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (i < len && s[i])
	{
		cp[i] = s[j];
		i++;
		j++;
	}
	return (cp);
}
