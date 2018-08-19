/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:33:49 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:33:50 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** BUILTINS: Free all the memory and exit
*/

static void		bi_exit(t_shell *s, char *cmd, char *bi_tmp)
{
	char	*tmp;
	int		rt;
	int		tag;
	int		i;

	rt = 0;
	i = 0;
	tag = 1;
	tmp = ft_strtrim(cmd);
	if (ft_strchr(tmp, ' ') && !(tag = 0))
		ft_putendl_fd(EX_WRONG_ARG, 2);
	while (tmp[i] && tag)
		if (!(ft_isdigit(tmp[i++])) && !(tag = 0))
			ft_putendl_fd(EX_WRONG_ARG, 2);
	if (tag)
	{
		rt = ft_atoi(tmp);
		tmp ? ft_memdel((void *)&tmp) : 0;
		cmd ? ft_memdel((void *)&cmd) : 0;
		bi_tmp ? ft_memdel((void *)&bi_tmp) : 0;
		flush_commands(s);
		flush_minishell(s);
		exit(rt);
	}
	cmd ? ft_memdel((void *)&cmd) : 0;
	tmp ? ft_memdel((void *)&tmp) : 0;
	bi_tmp ? ft_memdel((void *)&bi_tmp) : 0;
}

/*
** BUILTINS: Retrieve and print the current working directory
*/

static int		bi_pwd(t_shell *s)
{
	char *tmp;

	tmp = NULL;
	tmp = getcwd(tmp, 512);
	!tmp ? tmp = env_extract(s, "PWD") : (0);
	!tmp ? ft_putendl_fd(PWD_404, 2) : (0);
	tmp ? ft_putendl(tmp) : (0);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (0);
}

/*
** Recognize if the command is a builtin and reroute it accordingly
*/

int				builtins(t_shell *s, char *cmd, int i)
{
	char	*tmp;
	int		t;
	int		tag = 1;

	t = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	tmp = ft_strncpy(ft_strnew(i), cmd, i);
	if (!(ft_strcmp("exit", tmp)))
		bi_exit(s, ft_strsub(cmd, 4, (ft_strlen(cmd) - 4)), tmp);
	else if (!(ft_strcmp("echo", tmp)))
		tag = bi_echo(s, ft_strsub(cmd, 4, (ft_strlen(cmd) - 4)));
	else if (!(ft_strcmp("cd", tmp)))
		tag = bi_cd(s, cmd, ft_strlen(cmd));
	else if (!(ft_strcmp("env", tmp)))
		tag = bi_env(s, cmd);
	else if (!(ft_strcmp("pwd", tmp)))
		tag = bi_pwd(s);
	else if (!(ft_strcmp("unsetenv", tmp)))
		tag = bi_unsetenv(s, ft_strsub(cmd, 9, (ft_strlen(cmd) - 9)), 0, 0);
	else if (!(ft_strcmp("setenv", tmp)))
		tag = bi_setenv(s, ft_strsub(cmd, 7, (ft_strlen(cmd) - 7)));
	else
		process(s, cmd, NULL, NULL);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (tag);
}
