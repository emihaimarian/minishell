/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:47:11 by mienache          #+#    #+#             */
/*   Updated: 2018/01/14 17:48:45 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	n;

	i = 0;
	neg = -1;
	n = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = 10 * n - (str[i] - 48);
		i++;
	}
	n *= neg;
	return ((int)n);
}
