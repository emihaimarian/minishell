/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 21:47:24 by mienache          #+#    #+#             */
/*   Updated: 2018/01/13 21:52:59 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strdel_array(char ***as)
{
	char	**tab;

	tab = *as;
	while (*tab)
	{
		free(*tab);
		*tab = NULL;
		tab++;
	}
	free(*as);
	*as = NULL;
}
