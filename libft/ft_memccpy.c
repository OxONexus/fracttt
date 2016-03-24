/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:34:08 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:37:11 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*destptr;
	char	*srcptr;
	size_t	i;

	i = 0;
	destptr = (char*)dest;
	srcptr = (char*)src;
	while (i < n)
	{
		destptr[i] = srcptr[i];
		if (srcptr[i] == c)
			return ((char*)&destptr[i] + 1);
		i++;
	}
	return (NULL);
}
