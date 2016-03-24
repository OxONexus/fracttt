/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:34:15 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:37:20 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;
	size_t			i;

	s1ptr = (unsigned char*)s1;
	s2ptr = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s1ptr[i] != s2ptr[i])
			return ((s1ptr[i]) - (s2ptr[i]));
		i++;
	}
	return (0);
}
