/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:37:02 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:40:03 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *str;

	if (s)
	{
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		if (str)
		{
			while (start--)
				s++;
			ft_strncpy(str, s, len);
			str[len] = '\0';
		}
		return (str);
	}
	return (NULL);
}
