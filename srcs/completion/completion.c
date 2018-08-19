/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:35:07 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:35:08 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** AUTOCOMPLETION: Search for the value selected to output it
*/

t_comp		*c_seek_cursor(t_shell *s)
{
	t_comp			*ptr;

	if (s->comp->cursor)
		ptr = s->comp;
	else
	{
		ptr = s->comp->next;
		while (ptr->next != s->comp && !(ptr->cursor))
			ptr = ptr->next;
	}
	return (ptr);
}

/*
** AUTOCOMPLETION: Select the next node in the list
*/

void		c_next_item(t_shell *s)
{
	t_comp			*ptr;

	ptr = s->comp;
	while (!ptr->cursor)
		ptr = ptr->next;
	ptr->cursor = 0;
	ptr->next->cursor = 1;
}

/*
** AUTOCOMPLETION: Start the autocompletion by parsing and solving the rcmd
** Once that done, print out the result
*/

int			completion(t_shell *s, int *i)
{
	!(s->comp) ? c_match(s, NULL, NULL, i) : c_next_item(s);
	if (s->comp && s->comp != s->comp->next)
	{
		c_term_mv_down(s);
		c_printer(s);
		c_term_mv_back(s);
	}
	else if (s->comp && s->comp->name)
		c_clearing(s, i, 0);
	return (0);
}
