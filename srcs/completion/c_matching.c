/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_matching.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:34:50 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:34:51 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** AUTOCOMPLETION: Will split the raw command with the path terminated with /
**                 to the structure cpath and the rest to struct match for
**                 further use later.
*/

static int	c_splitter(t_shell *s)
{
	char			*tmp;
	int				i;
	int				tag;
	DIR				*rep;

	tag = 1;
	if ((rep = opendir(s->cpath)) && !closedir(rep))
		return (0);
	i = ft_strlen(s->cpath) - 1;
	tmp = ft_strdup(s->cpath);
	while (i && tmp[i] && tag && tmp[i] != '/')
		i--;
	tmp[i] == '/' ? i++ : 0;
	s->cpath ? ft_memdel((void *)&s->cpath) : 0;
	s->cpath = ft_strsub(tmp, 0, i);
	s->match ? ft_memdel((void *)&s->match) : 0;
	s->match = ft_strsub(tmp, i, ft_strlen(tmp) - i);
	s->match && !ft_strlen(s->match) ? ft_memdel((void *)&s->match) : 0;
	tmp ? ft_memdel((void *)&tmp) : 0;
	return (0);
}

/*
** AUTOCOMPLETION: Seek the binary part and throw the rest to the above function
**                 to know what and where to look for.
*/

static void	c_solver(t_shell *s, char *tmp, char *raw)
{
	int				i;
	int				tag;

	tag = 1;
	s->match ? ft_memdel((void *)&s->match) : 0;
	s->cpath ? ft_memdel((void *)&s->cpath) : 0;
	if ((i = ft_strcchr_rev(s->rcmd, ';')) && i++)
		tmp = ft_strsub(s->rcmd, i, s->lrcmd - i);
	else
		tmp = ft_strdup(s->rcmd);
	raw = ft_strtrim(tmp);
	tmp ? ft_memdel((void *)&tmp) : 0;
	i = 0;
	while (raw[i] && tag)
		(raw[i] && raw[i] == ' ' && raw[i - 1] != '\\') ? tag = 0 : i++;
	raw[i] == ' ' ? i++ : 0;
	if (i != (int)ft_strlen(raw))
		tmp = ft_strsub(raw, i, ft_strlen(raw) - i);
	s->cpath = cd_path_solver(s, tmp ? tmp : raw);
	c_splitter(s);
	raw ? ft_memdel((void *)&raw) : 0;
	tmp ? ft_memdel((void *)&tmp) : 0;
}

/*
** AUTOCOMPLETION: Exclude the autocompletion. Norme trick for above.
*/

static int	c_exclude_match(t_shell *s, int *i, char *tmp)
{
	tmp ? ft_memdel((void *)&tmp) : 0;
	return (store_commands(s, i, "/"));
}

/*
** AUTOCOMPLETION: Start of the autocompletion function. It will test out
**                 all the value retrieved by the above function to see if
**                 it's a folder. If so, it will output a / after the raw
**                 command.
*/

int			c_match(t_shell *s, char *cwd, char *path, int *i)
{
	DIR				*rep;
	char			*tmp;

	tmp = NULL;
	c_solver(s, NULL, NULL);
	s->match ? tmp = ft_strjoin(s->cpath, s->match) : 0;
	if (tmp && (rep = opendir(tmp)) && (!closedir(rep)))
	{
		if (tmp[ft_strlen(tmp) - 1] != '/')
			return (c_exclude_match(s, i, tmp));
		else if (tmp[ft_strlen(tmp) - 1] == '/')
			ft_memdel((void *)&s->match);
	}
	if (s->cpath && !s->match && (rep = opendir(s->cpath)) && (!closedir(rep)))
	{
		if (s->cpath[ft_strlen(s->cpath) - 1] != '/')
			return (c_exclude_match(s, i, tmp));
		else if (s->cpath[ft_strlen(s->cpath) - 1] == '/')
			ft_memdel((void *)&s->match);
	}
	c_folder_parser(s, s->cpath);
	tmp ? ft_memdel((void *)&tmp) : 0;
	cwd ? ft_memdel((void *)&cwd) : 0;
	path ? ft_memdel((void *)&path) : 0;
	return (0);
}
