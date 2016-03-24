/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:34:19 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:37:24 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *destptr;
	char *srcptr;

	destptr = dest;
	srcptr = (char*)src;
	while (n > 0)
	{
		*destptr++ = *srcptr++;
		n--;
	}
	return (dest);
}
