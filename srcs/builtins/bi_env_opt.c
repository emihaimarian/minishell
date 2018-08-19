/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:33:37 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:33:38 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** BUILTINS: support for env_u. Remove the var from the env
*/

static char		**unset_env_u(char **env, char *cmd, int i, int j)
{
	char	*tmp;
	char	**dump;

	tmp = NULL;
	dump = NULL;
	if (!(env))
		return (NULL);
	dump = ft_sstrnew(ft_sstrlen(env));
	while (env[i])
	{
		if (ft_strcchr(env[i], '=') == (int)ft_strlen(cmd))
		{
			tmp = ft_strsub(env[i], 0, (int)ft_strlen(cmd));
			(!(ft_strcmp(tmp, cmd))) ? (0) : (dump[j++] = ft_strdup(env[i]));
			tmp ? ft_memdel((void *)&tmp) : (0);
		}
		else
			dump[j++] = ft_strdup(env[i]);
		i++;
	}
	return (dump);
}

/*
** BUILTINS: env_exe support. Will remove from arg to_remove time to get a
** clean **arg with just the arg part for execve without the env portion
*/

static t_shell	*env_arg_cleaner(t_shell *s, int to_remove)
{
	int		i;
	char	**tmp;

	i = to_remove;
	if (!(s->marg))
		return (s);
	tmp = ft_sstrnew(ft_sstrlen(s->marg) - to_remove);
	while (s->marg[i])
	{
		tmp[i - to_remove] = ft_strdup(s->marg[i]);
		i++;
	}
	s->marg ? ft_sstrdel(s->marg) : (0);
	s->marg = NULL;
	tmp ? s->marg = ft_sstrdup(tmp) : (0);
	tmp ? ft_sstrdel(tmp) : 0;
	return (s);
}

/*
** BUILTINS: env support. Will skip in the **env searching the end part
*/

t_shell			*bi_env_exe(t_shell *s, char **cmd, int debounce)
{
	if (!cmd || !cmd[0])
		return (s);
	if (!(ft_strcmp(cmd[0], "env")) && debounce && env_arg_cleaner(s, 1))
		bi_env_exe(s, s->marg, 0);
	else if (!(ft_strcmp(cmd[0], "-v")) && env_arg_cleaner(s, 1))
		bi_env_exe(s, s->marg, debounce);
	else if (!(ft_strcmp(cmd[0], "-i")) && env_arg_cleaner(s, 1))
		bi_env_exe(s, s->marg, debounce);
	else if (!(ft_strcmp(cmd[0], "-u")) && env_arg_cleaner(s, 2))
		bi_env_exe(s, s->marg, debounce);
	return (s);
}

/*
** BUILTINS: env -i support will create q clear env
*/

t_shell			*bi_env_i(t_shell *s, char **cmd, int verbose)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (!(ft_strcmp(cmd[i], "-i")) && s->menv)
		{
			(verbose) ? (ft_putendl("#env clearing environ")) : (0);
			s->menv ? ft_sstrdel(s->menv) : (0);
			s->menv = NULL;
			s->alt = 1;
		}
		i++;
	}
	return (s);
}

/*
** BUILTINS: env -u var support. Will dump the env and unset the var
*/

t_shell			*bi_env_u(t_shell *s, char **cmd, int verbose)
{
	char	**tmp;
	int		i;

	if (s->alt)
		tmp = ft_sstrdup(s->menv);
	else
		tmp = ft_sstrdup(s->renv);
	i = 0;
	while (cmd[i])
	{
		if (!(ft_strcmp(cmd[i], "-u")) && cmd[i + 1])
		{
			verbose ? ft_putstr("#env unset: ") : (0);
			verbose ? ft_putendl(cmd[i + 1]) : (0);
			s->menv ? ft_sstrdel(s->menv) : (0);
			s->menv = unset_env_u(tmp, cmd[i + 1], 0, 0);
			tmp ? ft_sstrdel(tmp) : (0);
			tmp = ft_sstrdup(s->menv);
			s->alt = 1;
		}
		i++;
	}
	tmp ? ft_sstrdel(tmp) : (0);
	return (s);
}
