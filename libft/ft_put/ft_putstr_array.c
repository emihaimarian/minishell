/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 21:02:49 by mienache          #+#    #+#             */
/*   Updated: 2018/01/13 21:03:40 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_array(char **array, char sep)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_putstr(array[i]);
		if (array[i + 1] || sep == '\n')
			ft_putchar(sep);
		i++;
	}
}
