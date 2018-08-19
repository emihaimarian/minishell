/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:33:41 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:34:28 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** BUILTINS: Support function. Just trimming out the cmd.
*/

static char		*trimmer(char *cmd)
{
	char	*rt;

	rt = NULL;
	if (cmd)
		rt = ft_strtrim(cmd);
	if (rt[0] == '\0')
		rt ? ft_memdel((void *)&rt) : (0);
	if (rt && rt[0] == '=')
		rt ? ft_memdel((void *)&rt) : (0);
	if (rt && (int)ft_strlen(rt) == ft_strxcchr(rt, '='))
		rt ? ft_memdel((void *)&rt) : (0);
	cmd ? ft_memdel((void *)&cmd) : (0);
	return (rt);
}

/*
** BUILTINS: Split the name and var from the command and pass it to env_update()
*/

int				bi_setenv(t_shell *s, char *cmd)
{
	char	*t_name;
	char	*t_value;
	int		i;

	i = 0;
	t_name = NULL;
	t_value = NULL;
	cmd = trimmer(cmd);
	if (cmd && ft_strcchr(cmd, '='))
	{
		i = ft_strcchr(cmd, '=');
		(cmd[i] == '=') ? (i++) : (0);
		t_name = ft_strsub(cmd, 0, (i - 1));
		t_value = ft_strsub(cmd, i, ft_strlen(cmd) - i);
	}
	else if (cmd)
	{
		t_name = ft_strdup(cmd);
		t_value = ft_strnew(0);
	}
	cmd ? env_update(s, t_name, t_value) : (0);
	t_name ? ft_memdel((void *)&t_name) : (0);
	t_value ? ft_memdel((void *)&t_value) : (0);
	cmd ? ft_memdel((void *)&cmd) : (0);
	return (0);
}
