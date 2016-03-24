/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:36:24 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:39:28 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s && f)
	{
		str = ft_strdup((const char *)s);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (s + i != NULL && str[i] != 0)
		{
			str[i] = f((unsigned int)i, str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
