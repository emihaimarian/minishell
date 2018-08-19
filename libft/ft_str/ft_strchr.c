/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:02:56 by mienache          #+#    #+#             */
/*   Updated: 2018/01/14 19:32:28 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*str;

	a = (char)c;
	str = (char*)s;
	while (*str)
	{
		if (*str == a)
			return (str);
		str++;
	}
	if (*str == a)
		return (str);
	return (NULL);
}
