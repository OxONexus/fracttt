/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:36:21 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:39:25 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (s && f)
	{
		str = ft_strdup((const char *)s);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (str[i] != 0)
		{
			str[i] = f(str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
