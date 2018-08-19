/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:55:50 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 19:05:16 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*temp_dst;
	char	*temp_src;

	temp_dst = (char*)dst;
	temp_src = (char*)src;
	while (n-- > 0)
		*temp_dst++ = *temp_src++;
	return (dst);
}
