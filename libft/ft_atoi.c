/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:32:59 by apaget            #+#    #+#             */
/*   Updated: 2016/02/02 09:36:36 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_atoi(const char *s)
{
	int			i;
	int			sign;
	long int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(s[i]))
		i++;
	if ((!(s[i] >= '0' && s[i] <= '9')) && (!(s[i] == '+' || s[i] == '-')))
		return (0);
	if ((s[i] == '-' || s[i] == '+') && (ft_isdigit(s[i + 1]) == 0))
		return (0);
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0' && (s[i] >= '0') && (s[i] <= '9'))
	{
		nbr = nbr * 10 + (s[i] - '0');
		i++;
	}
	return ((int)(sign * nbr));
}
