/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:43:26 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/08 09:19:12 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*pt_cpy;

	i = 0;
	pt_cpy = NULL;
	if ((pt_cpy = malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
		return (pt_cpy);
	while (s1[i])
	{
		pt_cpy[i] = s1[i];
		i++;
	}
	pt_cpy[i] = 0;
	return (pt_cpy);
}
