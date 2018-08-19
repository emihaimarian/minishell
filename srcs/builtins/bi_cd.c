/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:33:16 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:33:19 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** BUILTINS: cd - support, will invert OLDPWD with PWD and go to that dir.
*/

static int	bi_dash(t_shell *s, char *cmd, char *cpwd, char *opwd)
{
	cpwd = env_extract(s, "PWD");
	opwd = env_extract(s, "OLDPWD");
	!cpwd ? ft_putendl_fd(CD_MIS_PWD, 2) : (0);
	!opwd ? ft_putendl_fd(CD_MIS_OLDPWD, 2) : (0);
	if (cpwd && opwd)
	{
		(opwd && (access(opwd, R_OK))) ? (ft_pputendl(CD_NO_RIGHT, opwd)) : (0);
		if (opwd && !(access(opwd, R_OK)) && chdir(opwd) == -1)
			ft_pputendl(CD_404, opwd);
		if (opwd && chdir(opwd) != -1)
		{
			env_update(s, "PWD", opwd);
			env_update(s, "OLDPWD", cpwd);
		}
	}
	cpwd ? ft_memdel((void *)&cpwd) : (0);
	opwd ? ft_memdel((void *)&opwd) : (0);
	cmd ? ft_memdel((void *)&cmd) : (0);
	return (0);
}

/*
** BUILTINS: Start of cd. Will update oldpwd and pwd in the env
*/

int			bi_cd(t_shell *s, char *cmd, int lcmd)
{
	char	*tmp;
	char	*npwd;
	char	*cpwd;

	tmp = NULL;
	cpwd = NULL;
	(lcmd > 2) ? (tmp = ft_strsub(cmd, 3, (lcmd - 3))) : (0);
	if (tmp && ft_strequ(tmp, "-"))
		return (bi_dash(s, tmp, NULL, NULL));
	cpwd = getcwd(cpwd, 512);
	!cpwd ? cpwd = env_extract(s, "PWD") : (0);
	npwd = (tmp) ? (cd_path_solver(s, tmp)) : (env_extract(s, "HOME"));
	(!npwd) ? (ft_putendl_fd(CD_MIS_HOME, 2)) : (0);
	(npwd && (access(npwd, R_OK))) ? (ft_pputendl(CD_NO_RIGHT, npwd)) : (0);
	if (npwd && !(access(npwd, R_OK)) && chdir(npwd) == -1)
		ft_pputendl(CD_404, npwd);
	if (npwd && chdir(npwd) != -1)
	{
		npwd ? env_update(s, "PWD", npwd) : (0);
		cpwd ? env_update(s, "OLDPWD", cpwd) : (0);
	}
	tmp ? ft_memdel((void *)&tmp) : (0);
	cpwd ? ft_memdel((void *)&cpwd) : (0);
	npwd ? ft_memdel((void *)&npwd) : (0);
	return (0);
}
