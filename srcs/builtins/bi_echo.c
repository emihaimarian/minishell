/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:33:25 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:33:26 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** BUILTINS: Retrieve the var name from env and print it
*/

static void	echo_env(t_shell *s, char *cmd)
{
	char	*t_chr;
	char	*t_ext;

	t_chr = NULL;
	t_ext = NULL;
	t_chr = ft_strsub(cmd, 1, (ft_strlen(cmd) - 1));
	t_ext = env_extract(s, t_chr);
	if (t_ext)
		ft_pputstr(t_ext, " ");
	else if (ft_strequ(t_ext, "?"))
		ft_pputstr(s->fstat, " ");
	else
		ft_putstr(ENV_404);
	t_chr ? ft_memdel((void *)&t_chr) : (0);
	t_ext ? ft_memdel((void *)&t_ext) : (0);
}

/*
** BUILTINS: print the quoted part of echo
*/

static void	echo_quoted(t_shell *s, char *cmd)
{
	char	*tmp;
	int		st;
	int		len;

	st = 1;
	len = 1;
	tmp = NULL;
	while (cmd[st + len])
	{
		while (cmd[st + len] && cmd[st + len] != '\"')
			len++;
		tmp = ft_strsub(cmd, st, len);
		((st >= 2) && cmd[st - 2] == ' ') ? (ft_putchar(' ')) : (0);
		(tmp[0] == '$') ? (echo_env(s, tmp)) : (ft_putstr(tmp));
		st += len + 1;
		while (cmd[st] && cmd[st] != '\"')
			st++;
		(cmd[st] == '\"') ? (st++) : (0);
		len = 0;
		tmp ? ft_memdel((void *)&tmp) : (0);
	}
	ft_putchar('\n');
}

/*
** BUILTINS: simply print of push it to echo_env is $ is found
*/

static void	echo_unquoted(t_shell *s, char *cmd)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	tmp = ft_strsplit(cmd, ' ');
	while (tmp[i])
	{
		(tmp[i][0] == '$') ? (echo_env(s, tmp[i])) : (ft_pputstr(tmp[i], " "));
		i++;
	}
	ft_putchar('\n');
	tmp ? ft_sstrdel(tmp) : (0);
}

/*
** BUILTINS: Start of echo builtins
*/

int			bi_echo(t_shell *s, char *cmd)
{
	char *tmp;

	tmp = NULL;
	tmp = ft_strtrim(cmd);
	if (tmp[0] != '\"')
		echo_unquoted(s, tmp);
	else
		echo_quoted(s, tmp);
	(cmd) ? (ft_memdel((void *)&cmd)) : (0);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (0);
}
