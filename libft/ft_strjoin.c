/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:36:11 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:39:10 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tmp;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (tmp == NULL)
			return (NULL);
		while (s1[i])
		{
			tmp[i] = s1[i];
			i++;
		}
		while (*s2)
		{
			tmp[i] = *s2;
			i++;
			s2++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
