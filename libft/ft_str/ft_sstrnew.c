/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 23:58:07 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 21:03:19 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstrnew(size_t size)
{
	char	**s;
	size_t	i;

	i = 0;
	if (!(s = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < (size))
		s[i++] = NULL;
	s[i] = NULL;
	return (s);
}
