/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:54:28 by mienache          #+#    #+#             */
/*   Updated: 2018/01/13 20:54:29 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstconcat(t_list *lnk_first_list, t_list *head_second_list)
{
	if (lnk_first_list && head_second_list)
	{
		while (lnk_first_list->next)
			lnk_first_list = lnk_first_list->next;
		lnk_first_list->next = head_second_list;
	}
}
