/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ull_toa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:55:05 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 15:38:34 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ull_toa(unsigned long long nb)
{
	int		len;
	char	*s;

	len = ull_len(nb);
	s = ft_strnew(len);
	if (nb == 0)
		*(s + len - 1) = '0';
	while (nb > 0 && len-- > 0)
	{
		*(s + len) = nb % 10 + '0';
		nb = nb / 10;
	}
	return (s);
}
