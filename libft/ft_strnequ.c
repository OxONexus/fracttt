/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:36:37 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:39:42 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (s1[i - 1] != s2[i - 1])
			return (0);
		return (1);
	}
	return (0);
}
