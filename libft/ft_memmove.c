/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:34:28 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:37:32 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;
	size_t			i;

	i = 0;
	str_dest = ((unsigned char *)dest);
	str_src = ((unsigned char *)src);
	if (str_dest > str_src)
	{
		while (i < n)
		{
			str_dest[n - 1] = str_src[n - 1];
			n--;
		}
		return (dest);
	}
	else
		while (i < n)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	return (dest);
}
