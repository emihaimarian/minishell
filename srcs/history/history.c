/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:35:46 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:35:47 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** HISTORY: Clear the prompt if it's the last command and down arrow is pushed.
*/

static t_shell	*history_cleared(t_shell *s, int *i)
{
	int		k;

	k = 0;
	TC_STR_LINE;
	while (k < s->prompt)
	{
		TC_MV_RIGHT;
		k++;
	}
	TC_DEL_LINE;
	*i = 0;
	s->rcmd ? ft_memdel((void *)&s->rcmd) : 0;
	return (s);
}

/*
** HISTORY: Browse the history to the present
*/

t_shell			*history_chr_down(t_shell *s, int *i)
{
	t_hist	*p_hist;

	p_hist = s->history;
	if (!(p_hist->cmd))
		return (s);
	if ((s->index) == s->history->id)
		return (history_cleared(s, i));
	while (p_hist && (p_hist->id != (s->index + 1)))
		p_hist = p_hist->next;
	if (s->rcmd)
	{
		while (*i)
		{
			*i -= 1;
			TC_MV_LEFT;
		}
		TC_DEL_LINE;
		(s->rcmd) ? (free(s->rcmd)) : (0);
	}
	s->rcmd = ft_strdup(p_hist->cmd);
	ft_putstr(p_hist->cmd);
	*i = ft_strlen(s->rcmd);
	s->lrcmd = ft_strlen(s->rcmd);
	(s->index < s->history->id) ? (s->index += 1) : (0);
	return (s);
}

/*
** HISTORY: Browse the history to the past
*/

t_shell			*history_chr_up(t_shell *s, int *i)
{
	t_hist	*p_hist;

	p_hist = s->history;
	if (!(p_hist->cmd))
		return (s);
	while (p_hist && (p_hist->id != s->index))
		p_hist = p_hist->next;
	if (s->rcmd)
	{
		while (*i)
		{
			*i -= 1;
			TC_MV_LEFT;
		}
		TC_DEL_LINE;
		(s->rcmd) ? (free(s->rcmd)) : (0);
	}
	s->rcmd = ft_strdup(p_hist->cmd);
	ft_putstr(p_hist->cmd);
	*i = ft_strlen(s->rcmd);
	s->lrcmd = ft_strlen(s->rcmd);
	(s->index > 1) ? (s->index -= 1) : (0);
	return (s);
}

/*
** HISTORY: Add the last rcmd to the history and update the pointer
*/

t_shell			*history_add(t_shell *s)
{
	t_hist	*p_hist;
	t_hist	*new;
	int		last_id;

	if (!(s->rcmd))
		return (s);
	p_hist = s->history;
	last_id = p_hist->id;
	if (last_id == 0)
	{
		p_hist->cmd = ft_strdup(s->rcmd);
		p_hist->id = 1;
		s->index = 1;
		return (s);
	}
	if (!(new = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	new->id = last_id + 1;
	new->cmd = ft_strdup(s->rcmd);
	new->next = p_hist;
	s->history = new;
	s->index = new->id;
	return (s);
}
