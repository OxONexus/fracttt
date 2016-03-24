/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:34:05 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:37:07 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = NULL;
	mem = (unsigned char *)malloc(size);
	if (mem)
	{
		while (size--)
		{
			mem[i] = 0;
			i++;
		}
	}
	return ((void *)mem);
}
