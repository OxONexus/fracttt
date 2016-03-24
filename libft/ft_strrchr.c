/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:36:46 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:39:53 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	while (count >= 0)
	{
		if (str[count] == (char)c)
			return ((char*)&str[count]);
		count--;
	}
	return (NULL);
}
