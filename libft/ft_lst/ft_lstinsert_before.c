/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_before.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:54:34 by mienache          #+#    #+#             */
/*   Updated: 2018/01/13 20:55:05 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert_before(t_list **alst, t_list *target, t_list *new)
{
	t_list *previous;
	t_list *node;

	node = *alst;
	previous = *alst;
	while (node)
	{
		if (node == target)
		{
			if (node == *alst)
				ft_lstadd_beginning(alst, new);
			else
			{
				new->next = target;
				previous->next = new;
			}
			break ;
		}
		previous = node;
		node = node->next;
	}
}
