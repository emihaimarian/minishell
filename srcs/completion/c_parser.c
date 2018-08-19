/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:34:55 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:34:55 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** AUTOCOMPLETION: Determine the column number needed for autocompletion
*/

static void	c_max_length(t_shell *s)
{
	t_comp				*tmp;
	int					max_x;
	int					max_y;

	if (s->comp && s->comp->name && s->comp == s->comp->next)
	{
		s->c_sx = s->comp->len;
		s->c_sy = 1;
	}
	else if (s->comp && s->comp->name)
	{
		max_x = s->comp->len;
		max_y = 1;
		tmp = s->comp->next;
		while (tmp != s->comp)
		{
			(max_x < tmp->len) ? (max_x = tmp->len) : (0);
			max_y++;
			tmp = tmp->next;
		}
		s->c_sx = max_x;
		s->c_sy = max_y;
	}
}

/*
** AUTOCOMPLETION: Exclude from the autocompletion folder with . and .. also
**                 item that doesn't match up with struct match.
*/

static int	c_exclude(t_shell *s, char *value)
{
	if (ft_strncmp(".", value, 1) == 0 || ft_strncmp("..", value, 2) == 0)
		return (1);
	if (s->match && ft_strnequ(s->match, value, ft_strlen(s->match)) != 1)
		return (1);
	if (s->match && ft_strequ(s->match, value))
		return (1);
	return (0);
}

/*
** AUTOCOMPLETION: Store the value of the parser and exclude item that don't
**                 begin with the same letter as match.
*/

static int	c_storing(t_shell *s, char *value, t_comp *tmp, int id_tag)
{
	if (c_exclude(s, value))
		return (1);
	if (!(tmp = (t_comp *)malloc(sizeof(t_comp))))
		return (1);
	tmp->name = ft_strdup(value);
	tmp->len = ft_strlen(tmp->name);
	tmp->cursor = 0;
	if (s->comp == NULL)
	{
		s->comp = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
		tmp->cursor++;
		tmp->id = 1;
	}
	else
	{
		tmp->id = s->comp->prev->id + 1;
		s->comp->prev->next = tmp;
		tmp->prev = s->comp->prev;
		tmp->next = s->comp;
		s->comp->prev = tmp;
	}
	id_tag++;
	return (0);
}

/*
** AUTOCOMPLETION: Parser for the folder pointed by struct cpath.
*/

int			c_folder_parser(t_shell *s, char *path)
{
	DIR				*rep;
	struct dirent	*dirc;
	int				i;

	i = 1;
	if (!(rep = opendir(path)))
		return (1);
	while ((dirc = readdir(rep)))
		c_storing(s, dirc->d_name, NULL, i++);
	s->comp && s->comp->name ? c_max_length(s) : 0;
	s->c_pline = s->win_x / (s->c_sx + 1);
	s->c_line = 0;
	while ((s->c_line * s->c_pline) < s->c_sy)
		s->c_line++;
	if (s->win_x < s->c_sx)
	{
		s->c_pline = 0;
		s->c_line = 0;
	}
	closedir(rep);
	return (0);
}
