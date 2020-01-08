/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:17:57 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/07 09:49:55 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *alloc;

	alloc = NULL;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if ((alloc = malloc(count * size)) == NULL)
		return (alloc);
	ft_bzero(alloc, count * size);
	return (alloc);
}
