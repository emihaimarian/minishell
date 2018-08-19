/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:56:23 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 21:06:18 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_sstradd(char **s, char *add)
{
	char	**rt;
	int		i;

	i = 0;
	rt = ft_sstrnew(ft_sstrlen(s) + 1);
	while (s[i])
	{
		rt[i] = ft_strdup(s[i]);
		i++;
	}
	rt[i] = ft_strdup(add);
	ft_sstrdel(s);
	s = rt;
	return (rt);
}
