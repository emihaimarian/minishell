/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:14:21 by mienache          #+#    #+#             */
/*   Updated: 2018/02/12 18:20:11 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int			size;
	char		*s;
	long int	nb;

	size = ft_intsize(n);
	if (!(s = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	*(s + size) = '\0';
	nb = (long int)n;
	if (nb == 0)
		*s = '0';
	if (nb < 0)
	{
		*s = '-';
		nb = -nb;
	}
	while (nb != 0 && size-- > 0)
	{
		*(s + size) = nb % 10 + 48;
		nb = nb / 10;
	}
	return (s);
}
