/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:40:05 by alao              #+#    #+#             */
/*   Updated: 2018/03/12 20:35:00 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** AUTOCOMPLETION: Print the name with or without an underline
*/

static void	c_printer_node(t_comp *lst)
{
	lst->cursor ? ft_putstr(tgetstr("us", NULL)) : (0);
	lst->cursor ? (ft_putstr_fd("\033[31m", 2)) : (0);
	ft_putstr_fd(lst->name, 2);
	ft_putstr_fd("\033[00m", 2);
	lst->cursor ? ft_putstr(tgetstr("ue", NULL)) : (0);
}

/*
** AUTOCOMPLETION: Cycle through the line to print on the same line the
** number of time to fill it PER LINE
*/

static int	c_printer_line(t_shell *s, t_comp *lst, int loop, int i)
{
	t_comp	*tmp;

	tmp = lst->next;
	c_printer_node(lst);
	while (loop)
	{
		i = 1;
		while (i++ < (s->c_line))
		{
			if (tmp == s->comp)
				return (0);
			tmp = tmp->next;
		}
		if (tmp != s->comp)
		{
			i = lst->len;
			while (i++ < (s->c_sx + 1))
				ft_putstr(" ");
			c_printer_node(tmp);
			lst = tmp;
			tmp = tmp->next;
		}
		loop--;
	}
	return (0);
}

/*
** AUTOCOMPLETION: Control the number of time it cycle for LINE
*/

void		c_printer(t_shell *s)
{
	t_comp	*tmp;
	int		loop;

	tmp = s->comp;
	loop = s->c_line;
	while (loop)
	{
		c_printer_line(s, tmp, s->c_pline, 1);
		loop > 1 ? ft_putstr(tgetstr("do", NULL)) : (0);
		tmp = tmp->next;
		loop--;
	}
}
