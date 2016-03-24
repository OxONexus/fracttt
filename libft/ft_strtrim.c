/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:37:06 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:40:08 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	j;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = 0;
	k = 0;
	while (s[j])
	{
		if (s[j] != ' ' && s[j] != '\t' && s[j] != '\n')
		{
			j++;
			k = j;
		}
		else
			j++;
	}
	if (s && k == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, i, (k - i)));
}
