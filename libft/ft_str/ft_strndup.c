/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 21:50:34 by mienache          #+#    #+#             */
/*   Updated: 2018/01/13 23:15:14 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s;
	size_t	i;

	s = ft_strnew(n);
	if (!s)
		return (NULL);
	if (s1)
	{
		i = 0;
		while (i < n)
		{
			s[i] = s1[i];
			i++;
		}
	}
	return (s);
}
