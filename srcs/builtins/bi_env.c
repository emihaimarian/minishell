/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:33:31 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:33:32 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** BUILTINS: Recon options for env
*/

static t_shell	*env_recon(t_shell *s, char **cmd)
{
	int		i;
	int		verbose;

	i = 0;
	verbose = 0;
	while (cmd[i])
		if (!(ft_strcmp(cmd[i++], "-v")))
			verbose = 1;
	(s->alt) ? (0) : (s->menv = ft_sstrdup(s->renv));
	bi_env_u(s, cmd, verbose);
	bi_env_i(s, cmd, verbose);
	if (cmd && !s->marg)
		s->marg = ft_sstrdup(cmd);
	bi_env_exe(s, s->marg, 1);
	return (s);
}

/*
** BUILTINS: Print the env
*/

static int		env_print(t_shell *s)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = NULL;
	ptr = s->alt ? s->menv : s->renv;
	if (ptr)
	{
		while (ptr && ptr[i])
		{
			ft_putstr("\e[1m\e[32m");
			(i < 10) ? (write(1, "0", 1)) : (0);
			ft_putnbr(i);
			ft_putstr(" - ");
			ft_putstr("\e[0m");
			ft_putendl(ptr[i++]);
		}
	}
	return (0);
}

/*
** BUILTINS: Start of env
*/

int				bi_env(t_shell *s, char *cmd)
{
	int		i;
	char	**splitted;
	char	*result;

	i = 0;
	splitted = NULL;
	result = NULL;
	result = ft_strtrim(cmd);
	if (ft_strlen(result) == 3)
	{
		result ? ft_memdel((void *)&result) : (0);
		return (env_print(s));
	}
	splitted = ft_strsplit(result, ' ');
	result ? ft_memdel((void *)&result) : (0);
	splitted ? env_recon(s, splitted) : (0);
	if (s->marg && (result = ft_sstrtostr(s->marg, " ")))
	{
		if (result[ft_strlen(result) - 1] == ' ')
			result[ft_strlen(result) - 1] = '\0';
		builtins(s, result, 0);
		result ? ft_memdel((void *)&result) : (0);
	}
	splitted ? ft_sstrdel(splitted) : (0);
	return (0);
}
