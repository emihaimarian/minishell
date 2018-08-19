/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:35:53 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:35:54 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Cycle through the rcmd splitted by ; to builtins_recon()
*/

t_shell				*processing(t_shell *s, char *raw, char *tmp)
{
	int		i;

	i = 0;
	s->rcmd ? tmp = ft_strtrim(s->rcmd) : 0;
	if (tmp && ft_strlen(tmp) > 1 && tmp[ft_strlen(tmp) - 1] == ';')
		raw = ft_strsub(tmp, 0, ft_strlen(tmp) - 1);
	else if (tmp)
		raw = ft_strdup(tmp);
	raw ? s->cmd = ft_strsplit(raw, ';') : 0;
	raw ? ft_memdel((void *)&raw) : 0;
	tmp ? ft_memdel((void *)&tmp) : 0;
	while (s->cmd && s->cmd[i])
	{
		if (s->cmd[i])
		{
			tmp = ft_strtrim(s->cmd[i++]);
			builtins(s, tmp, 0);
			tmp ? ft_memdel((void *)&tmp) : 0;
		}
	}
	(s->rcmd) ? flush_commands(s) : (0);
	return (s);
}

/*
** Display the prompt and solve the home path to get the tilde
*/

static void			dsp_prompt(t_shell *s, char *cwd, char *tmp, char *tmp2)
{
	int		lcwd;

	cwd = getcwd(cwd, 512);
	!cwd ? cwd = env_extract(s, "PWD") : (0);
	cwd ? lcwd = ft_strlen(cwd) : (0);
	if (cwd && (tmp = env_extract(s, "HOME"))
		&& !(ft_strncmp(tmp, cwd, ft_strlen(tmp))))
	{
		tmp2 = ft_strsub(cwd, ft_strlen(tmp), lcwd - ft_strlen(tmp));
		ft_memdel((void *)&tmp);
		tmp = ft_strjoin("~", tmp2);
		ft_memdel((void *)&tmp2);
	}
	else
	{
		tmp ? ft_memdel((void *)&tmp) : 0;
		tmp = cwd ? ft_strdup(cwd) : ft_strdup("#");
	}
	ft_pputstr("\e[36m", tmp);
	(!(ft_strcmp(tmp, "~"))) ? (ft_putstr("/")) : (0);
	ft_putstr("> \e[0m");
	s->prompt = ft_strlen(tmp) + 2;
	(!(ft_strcmp(tmp, "~"))) ? (s->prompt++) : (0);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&cwd);
}

/*
** Minishell main loop
*/

int					minishell(t_shell *s)
{
	(s->rcmd) ? (flush_commands(s)) : (0);
	while (42)
	{
		signal_handler();
		dsp_prompt(s, NULL, NULL, NULL);
		if (s->adv)
			get_commands(s);
		else
			get_next_line(0, &s->rcmd);
		if (s->rcmd)
			processing(s, NULL, NULL);
	}
	return (0);
}

/*
** Where all the magic begin
*/

int					main(int ac, char **av, char **env)
{
	t_shell	s;

	(void)ac;
	(void)av;
	s = *get_shell_ptr(&s, 1);
	init_shell(&s);
	if (tc_init(&s))
		ft_putendl_fd(ERR_TERM, 2);
	if (!(env_saver(&s, env)))
		ft_putendl_fd(ERR_ENV, 2);
	s.adv ? welcome(&s) : 0;
	minishell(&s);
	flush_minishell(&s);
	return (0);
}
