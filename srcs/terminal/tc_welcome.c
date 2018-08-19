/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_welcome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:36:13 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:36:20 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Stats
*/

static void		w_stats(void)
{
	int		ln;
	int		ch;

	ln = 2842;
	ch = 76852;
	ft_putstr("\e[1m\e[92m");
	ft_putstr("  ");
	ft_putnbr(ch);
	ft_putstr(" characters on ");
	ft_putnbr(ln);
	ft_putstr(" lines for one lousy prompt... That's a lot.");
	ft_putendl("");
	ft_putstr("\e[39m");
}

/*
** Display a welcome message if there's enough place and if termcaps is enabled.
*/

int				welcome(t_shell *s)
{
	if (s->win_x <= 72 || !s->adv)
		return (1);
	TC_CLEAR_SCR;
	w_stats();
	return (0);
}
