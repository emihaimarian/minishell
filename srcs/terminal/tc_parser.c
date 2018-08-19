/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:36:10 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:36:10 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** TERMCAPS: Redistribution to function per key type
*/

static int		hooker(t_shell *s, int *i, char *buffer, unsigned int key)
{
	if (s->comp && key != K_TAB)
		c_clearing(s, i, key);
	else
	{
		(key != K_ENTER && ft_isprint(key)) ? store_commands(s, i, buffer) : 0;
		(key == K_RETURN && (s->rcmd) && *i > 0) ? del_rcmd(s, *i, key, i) : 0;
		if (key == K_DEL && (s->rcmd) && (*i < (int)ft_strlen(s->rcmd)))
			del_rcmd(s, *i + 1, key, i);
		(key == K_UP) ? history_chr_up(s, i) : 0;
		(key == K_DOWN) ? history_chr_down(s, i) : 0;
		(key == K_LEFT || key == K_RIGHT) ? cursor(s, i, key) : 0;
		(key == K_HOME || key == K_END) ? cursor(s, i, key) : 0;
		(key == K_ALT_LEFT || key == K_ALT_RIGHT) ? cursor_word(s, i, key) : 0;
		(key == K_TAB && s->rcmd) ? completion(s, i) : 0;
		if (!s->comp && key == K_ENTER)
			return (0);
	}
	(key == K_CTRL_D) ? signal_recon(SIGQUIT) : 0;
	return (1);
}

/*
** TERMCAPS: Parser specific to advanced function. The standard one is
** get_next_line which can be found in the libft
*/

t_shell			*get_commands(t_shell *s)
{
	char			*buffer[5];
	unsigned int	kcode;
	int				i;

	i = 0;
	kcode = 0;
	ft_memset(buffer, 0, 5);
	while ((read(0, buffer, 5)) > 0
		&& hooker(s, &i, (char *)buffer, (unsigned int)*buffer))
	{
		kcode += (unsigned int)*buffer;
		(kcode > K_KON) ? (kcode = 0) : (0);
		ft_memset(buffer, 0, 5);
	}
	if (kcode == K_KON && (!(ft_strcmp(s->rcmd, "ba"))))
	{
		ft_putendl("\n\nNerdz.");
		ft_memdel((void *)&s->rcmd);
	}
	ft_putstr("\n");
	return (s);
}
