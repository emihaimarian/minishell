/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 19:55:39 by alao              #+#    #+#             */
/*   Updated: 2016/10/29 07:21:40 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Clear the memory related to autocompletion
*/

void			flush_completion(t_shell *s)
{
	t_comp		*p_cmp;
	t_comp		*p_del;

	if (s->comp && s->comp->name)
	{
		p_cmp = s->comp;
		s->comp->prev ? (s->comp = s->comp->prev) : 0;
		p_cmp->prev->next = NULL;
		while (p_cmp->next)
		{
			p_cmp->name ? ft_memdel((void *)&p_cmp->name) : 0;
			p_cmp->prev = NULL;
			p_del = p_cmp;
			p_cmp = p_cmp->next;
			p_del->next = NULL;
			p_del ? ft_memdel((void *)&p_del) : 0;
		}
		(s->comp->name) ? ft_memdel((void *)&s->comp->name) : 0;
	}
	(s->comp) ? ft_memdel((void *)&s->comp) : (0);
	(s->match) ? ft_memdel((void *)&s->match) : (0);
	(s->cpath) ? ft_memdel((void *)&s->cpath) : (0);
}

/*
** Clear the memory between two call after the rcmd has been proceeded
*/

void			flush_commands(t_shell *s)
{
	(s->rcmd && s->adv) ? history_add(s) : 0;
	(s->rcmd) ? (s->index = s->history->id) : 0;
	(s->rcmd) ? ft_memdel((void *)&s->rcmd) : 0;
	(s->cmd) ? ft_sstrdel(s->cmd) : 0;
	s->cmd = NULL;
	(s->menv) ? ft_sstrdel(s->menv) : 0;
	s->menv = NULL;
	(s->marg) ? ft_sstrdel(s->marg) : 0;
	s->marg = NULL;
	s->lrcmd = 0;
	s->alt = 0;
	s->c_sx = 0;
	s->c_sy = 0;
	s->c_pline = 0;
	s->c_line = 0;
	flush_completion(s);
}

/*
** Clear all the memory left
*/

void			flush_minishell(t_shell *s)
{
	t_hist	*p_hist;
	t_hist	*p_backup;

	p_hist = s->history;
	p_backup = NULL;
	(s->rcmd) ? (ft_memdel((void *)&s->rcmd)) : (0);
	(s->menv) ? (ft_sstrdel(s->menv)) : (0);
	s->menv = NULL;
	(s->renv) ? (ft_sstrdel(s->renv)) : (0);
	s->renv = NULL;
	while (p_hist != NULL)
	{
		p_backup = p_hist->next;
		(p_hist->cmd) ? ft_memdel((void *)&p_hist->cmd) : (0);
		(p_hist) ? ft_memdel((void *)&p_hist) : (0);
		p_hist = p_backup;
	}
	tc_close(s);
}

/*
** Initialize value for the function history and autocompletion
*/

static t_shell	*init_options(t_shell *s)
{
	if (!(s->history = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	s->history->id = 0;
	s->history->cmd = NULL;
	s->history->next = NULL;
	s->index = 0;
	s->comp = NULL;
	s->cpath = NULL;
	s->match = NULL;
	s->c_pline = 0;
	s->c_line = 0;
	s->c_sx = 0;
	s->c_sy = 0;
	return (s);
}

/*
** Initialize the main structure
*/

t_shell			*init_shell(t_shell *shell)
{
	shell->rcmd = NULL;
	shell->cmd = NULL;
	shell->renv = NULL;
	shell->menv = NULL;
	shell->marg = NULL;
	shell->adv = 0;
	shell->alt = 0;
	shell->win_x = 0;
	shell->win_y = 0;
	shell->fstat = "0";
	init_options(shell);
	return (shell);
}
