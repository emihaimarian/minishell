/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 21:46:58 by mienache          #+#    #+#             */
/*   Updated: 2018/01/13 21:47:16 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace(char *origin, char *rep, char *with)
{
	char		*start;
	size_t		size_rep;
	char		*new;

	if (!(start = ft_strstr(origin, rep)))
		return (origin);
	size_rep = ft_strlen(rep);
	new = ft_strnew(ft_strlen(origin) + ft_strlen(rep) + ft_strlen(with));
	ft_strncpy(new, origin, start - origin);
	ft_strcat(new, with);
	ft_strcat(new, start + size_rep);
	return (new);
}
