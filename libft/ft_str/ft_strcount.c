/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 21:48:15 by mienache          #+#    #+#             */
/*   Updated: 2018/01/13 21:48:23 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcount(char *str, char to_find)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == to_find)
			count++;
		str++;
	}
	return (count);
}
