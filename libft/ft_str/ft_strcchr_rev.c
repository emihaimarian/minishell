/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:41:30 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 21:05:31 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcchr_rev(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && s[i] && s[i] != (char)c)
		i--;
	if (i >= 0 && s[i] == (char)c)
		return (i);
	return (0);
}
