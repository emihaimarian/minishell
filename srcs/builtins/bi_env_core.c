/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:34:03 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:34:04 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** BUILTINS: Extract the value of name and return it
*/

char			*env_extract(t_shell *s, char *name)
{
	char	*tmp;
	char	*rt;
	int		i;
	int		tlen;

	tmp = NULL;
	rt = NULL;
	i = 0;
	tlen = ft_strlen(name);
	while (s->renv && s->renv[i] && !(rt))
	{
		if (ft_strcchr(s->renv[i], '=') == tlen)
		{
			tmp = ft_strsub(s->renv[i], 0, tlen);
			if (!(ft_strcmp(tmp, name)) && tlen++)
				rt = ft_strsub(s->renv[i], tlen, ft_strlen(s->renv[i]) - 1);
			ft_memdel((void *)&tmp);
		}
		i++;
	}
	return (rt);
}

/*
** BUILTINS: Support function for env_update. Norme.
*/

static int		env_update_inside(t_shell *s, int i, char *name, char *value)
{
	char	*t_test;
	char	*t_name;

	t_name = NULL;
	t_test = NULL;
	t_name = ft_strjoin(name, "=");
	t_test = ft_strsub(s->renv[i], 0, ft_strlen(name));
	if (!(ft_strcmp(t_test, name)))
	{
		free(s->renv[i]);
		s->renv[i] = ft_strjoin(t_name, value);
		t_test ? ft_memdel((void *)&t_test) : (0);
		t_name ? ft_memdel((void *)&t_name) : (0);
		return (0);
	}
	t_test ? ft_memdel((void *)&t_test) : (0);
	t_name ? ft_memdel((void *)&t_name) : (0);
	return (1);
}

/*
** BUILTINS: Find and replace the value of name
*/

t_shell			*env_update(t_shell *s, char *name, char *value)
{
	char	*t_add;
	char	*t_name;
	int		i;
	int		tag;

	t_add = NULL;
	t_name = NULL;
	i = 0;
	tag = 1;
	t_name = ft_strjoin(name, "=");
	while (s->renv && s->renv[i] && tag)
	{
		if (ft_strcchr(s->renv[i], '=') == (int)ft_strlen(name))
			tag = env_update_inside(s, i, name, value);
		i++;
	}
	tag ? t_add = ft_strjoin(t_name, value) : 0;
	tag ? s->renv = ft_sstradd(s->renv, t_add) : 0;
	t_add ? ft_memdel((void *)&t_add) : (0);
	t_name ? ft_memdel((void *)&t_name) : (0);
	return (s);
}

/*
** Upgrade the shlvl in the env
*/

static t_shell	*env_shlvl(t_shell *s)
{
	char	*t_lvl;
	int		lvlup;

	t_lvl = NULL;
	lvlup = 0;
	t_lvl = env_extract(s, "SHLVL");
	if (t_lvl == NULL)
		t_lvl = ft_strdup("1");
	else
	{
		lvlup = ft_atoi(t_lvl) + 1;
		t_lvl ? ft_memdel((void *)&t_lvl) : (0);
		t_lvl = ft_itoa(lvlup);
	}
	env_update(s, "SHLVL", t_lvl);
	t_lvl ? ft_memdel((void *)&t_lvl) : (0);
	return (s);
}

/*
** Copy the current env to minishell env
*/

t_shell			*env_saver(t_shell *s, char **env)
{
	if (!(ft_sstrlen(env)) && (s->renv = ft_sstrnew(0)))
		return (NULL);
	s->renv = ft_sstrdup(env);
	env_shlvl(s);
	return (s);
}
