/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:34:11 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:37:16 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sptr;
	size_t	i;

	i = 0;
	sptr = (char*)s;
	while (i < n)
	{
		if (sptr[i] == (char)c)
			return (&sptr[i]);
		i++;
	}
	return (NULL);
}
