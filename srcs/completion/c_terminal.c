/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_terminal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:35:03 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:35:04 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** AUTOCOMPLETION: Move the terminal up by the number of line needed and
** move it back up to the original position
*/

void			c_term_mv_back(t_shell *s)
{
	int		i;
	int		lcmd;

	i = 0;
	while (i != (s->c_line))
	{
		ft_putstr(tgetstr("up", NULL));
		i++;
	}
	ft_putstr(tgetstr("cr", NULL));
	i = 0;
	lcmd = s->prompt;
	s->rcmd ? lcmd += (int)ft_strlen(s->rcmd) : 0;
	while (i < lcmd)
	{
		ft_putstr(tgetstr("nd", NULL));
		i++;
	}
}

/*
** AUTOCOMPLETION: Move the terminal down by the number of line needed and
** move it back up to the first line under the prompt
*/

void			c_term_mv_down(t_shell *s)
{
	int		i;

	i = 0;
	while (i < s->c_line)
	{
		ft_putstr(tgetstr("do", NULL));
		i++;
	}
	i = 0;
	while (i != (s->c_line - 1))
	{
		ft_putstr(tgetstr("up", NULL));
		i++;
	}
}
