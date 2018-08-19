/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:03:38 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 17:17:16 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s1_dup;
	char	*temp;

	if (!(s1_dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	temp = s1_dup;
	while (*s1)
	{
		*temp++ = *s1++;
	}
	*temp = '\0';
	return (s1_dup);
}
