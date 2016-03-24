/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:34:32 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:37:36 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	ptr = (char*)s;
	while (n--)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (s);
}
