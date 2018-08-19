/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:36:30 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:36:32 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <stdio.h>

# define CD_404				"cd: No such file or directory: "
# define CD_NO_RIGHT		"cd: Access denied for: "
# define CD_MIS_PWD			"cd: Cannot retrieve PWD path"
# define CD_MIS_OLDPWD		"cd: Cannot retrieve OLDPWD path."
# define CD_MIS_HOME		"cd: Cannot retrieve HOME path."
# define PWD_404			"pwd: Cannot retrieve current working directory."
# define EX_WRONG_ARG		"exit: Wrong argument. Use only digits."
# define ENV_404			"env: variable doesn't exist in env"
# define SET_ERR			"set: Wrong syntax. Use: setenv var=value"
# define ERR_UNST			"unset: Wrong syntax. Use: unsetenv var"
# define NO_RIGHTS			"minishell: Permission denied for :"
# define NO_FOUND			"minishell: Command not found: "
# define ERR_TERM			"Term infos is missing. Disabled: advanced edition."
# define ERR_ENV			"Env is missing from parent processus."

# define TC_CLEAR_SCR		ft_putstr(tgetstr("cl", NULL))
# define TC_DELETE			ft_putstr(tgetstr("dc", NULL))
# define TC_STR_INSERT		ft_putstr(tgetstr("im", NULL))
# define TC_END_INSERT		ft_putstr(tgetstr("ei", NULL))
# define TC_STR_LINE		ft_putstr(tgetstr("cr", NULL))
# define TC_DEL_LINE		ft_putstr(tgetstr("ce", NULL))
# define TC_MV_UP			ft_putstr(tgetstr("up", NULL))
# define TC_MV_DOWN			ft_putstr(tgetstr("do", NULL))
# define TC_MV_LEFT			ft_putstr(tgetstr("le", NULL))
# define TC_MV_RIGHT		ft_putstr(tgetstr("nd", NULL))

# define K_KON				35051931
# define K_UP				4283163
# define K_DOWN				4348699
# define K_LEFT				4479771
# define K_RIGHT			4414235
# define K_ALT_LEFT			1146821403
# define K_ALT_RIGHT		1130044187
# define K_HOME				4741915
# define K_END				4610843
# define K_ESC				27
# define K_ENTER			10
# define K_RETURN			127
# define K_DEL				2117294875
# define K_TAB				9
# define K_CTRL				1
# define K_CTRL_D			4

typedef struct				s_hist
{
	int						id;
	char					*cmd;
	struct s_hist			*next;
}							t_hist;

typedef struct				s_comp
{
	int						id;
	char					*name;
	int						len;
	int						cursor;
	struct s_comp			*next;
	struct s_comp			*prev;
}							t_comp;

typedef struct				s_shell
{
	struct termios			term;
	int						adv;
	char					*rcmd;
	int						lrcmd;
	char					*fstat;
	char					**cmd;
	char					**renv;
	char					**menv;
	char					**marg;
	int						alt;
	int						prompt;
	int						win_x;
	int						win_y;
	struct s_hist			*history;
	int						index;
	struct s_comp			*comp;
	char					*cpath;
	char					*match;
	int						c_sx;
	int						c_sy;
	int						c_pline;
	int						c_line;
}							t_shell;

/*
** Basic functions
*/

int							welcome(t_shell *s);
void						signal_handler(void);
void						signal_recon(int sig);
t_shell						*init_shell(t_shell *shell);
t_shell						*get_shell_ptr(t_shell *s, int i);
t_shell						*get_commands(t_shell *s);
t_shell						*processing(t_shell *s, char *raw, char *tmp);
void						flush_minishell(t_shell *s);
void						flush_commands(t_shell *s);
int							minishell(t_shell *s);

/*
** Termcaps handling and subfunctions
*/

int							tc_init(t_shell *s);
int							tc_refresh(t_shell *s);
int							tc_close(t_shell *s);
int							store_commands(t_shell *s, int *i, char *buffer);
int							cursor(t_shell *s, int *i, unsigned int key);
int							cursor_word(t_shell *s, int *i, unsigned int key);
t_shell						*edit_rcmd(t_shell *s, int i, char *buffer);
t_shell						*del_rcmd(t_shell *s, int i, int key, int *r_i);

/*
** History support if termcaps is available
*/

t_shell						*history_add(t_shell *s);
t_shell						*history_chr_up(t_shell *s, int *i);
t_shell						*history_chr_down(t_shell *s, int *i);

/*
** Auto-completion support if termcaps is available
*/

int							completion(t_shell *s, int *i);
t_comp						*c_seek_cursor(t_shell *s);
int							c_match(t_shell *s, char *tmp, char *path, int *i);
int							c_folder_parser(t_shell *s, char *path);
void						c_term_mv_down(t_shell *s);
void						c_term_mv_back(t_shell *s);
void						c_printer(t_shell *s);
int							c_put_single(t_shell *s, int *i);
void						c_clearing(t_shell *s, int *i, unsigned int key);
void						flush_completion(t_shell *s);

/*
** Buildins related functions
*/

t_shell						*env_saver(t_shell *s, char **env);
t_shell						*env_update(t_shell *s, char *name, char *value);
char						*env_extract(t_shell *s, char *name);
char						*cd_path_solver(t_shell *s, char *cmd);
int							builtins(t_shell *s, char *cmd, int i);
int							bi_cd(t_shell *s, char *cmd, int lcmd);
int							bi_echo(t_shell *s, char *cmd);
int							bi_setenv(t_shell *s, char *cmd);
int							bi_unsetenv(t_shell *s, char *cmd, int i, int j);
int							bi_env(t_shell *s, char *cmd);
t_shell						*bi_env_u(t_shell *s, char **cmd, int verbose);
t_shell						*bi_env_i(t_shell *s, char **cmd, int verbose);
t_shell						*bi_env_exe(t_shell *s, char **cmd, int debounce);

/*
** Processing commands functions
*/

t_shell						*process(t_shell *s, char *cmd, char *ex, char *tp);

#endif
