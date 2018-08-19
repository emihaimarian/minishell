/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:00:23 by mienache          #+#    #+#             */
/*   Updated: 2018/01/14 18:01:41 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*m;
	unsigned char	*old;

	m = (unsigned char*)dst;
	old = (unsigned char*)src;
	if (src > dst)
	{
		while (len-- > 0)
			*m++ = *old++;
	}
	else
	{
		m += len;
		old += len;
		while (len-- > 0)
			*--m = *--old;
	}
	return (dst);
}
