/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_hooker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:36:02 by mienache          #+#    #+#             */
/*   Updated: 2018/03/12 20:36:03 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** TERMCAPS: Store the content of the buffer and print it
*/

int			store_commands(t_shell *s, int *i, char *buffer)
{
	edit_rcmd(s, *i, buffer);
	TC_STR_INSERT;
	ft_putstr(buffer);
	TC_END_INSERT;
	*i += 1;
	s->lrcmd = ft_strlen(s->rcmd);
	return (1);
}

int			cursor_word(t_shell *s, int *i, unsigned int key)
{
	if (key == K_ALT_LEFT)
	{
		if (*i == 0)
			return (0);
		if (*i == 1 && !(*i -= 1))
			TC_MV_LEFT;
		if (*i && *i - 1 && s->rcmd[*i - 1] == ' ' && (*i -= 1))
			TC_MV_LEFT;
		while (*i && *i - 1 && s->rcmd[*i - 1] != ' ' && (*i -= 1))
			TC_MV_LEFT;
		if (*i && *i == 1 && s->rcmd[*i] != ' ' && !(*i -= 1))
			TC_MV_LEFT;
	}
	if (key == K_ALT_RIGHT)
	{
		if (*i == s->lrcmd)
			return (0);
		if (*i - 1 < s->lrcmd && s->rcmd[*i - 1] == ' ' && (*i += 1))
			TC_MV_RIGHT;
		if (*i == 0 && *i + 1 < s->lrcmd && s->rcmd[*i] != ' ' && (*i += 1))
			TC_MV_RIGHT;
		while (*i < s->lrcmd && s->rcmd[*i - 1] != ' ' && (*i += 1))
			TC_MV_RIGHT;
	}
	return (0);
}

/*
** TERMCAPS: Moving key support - arrows, home, end
*/

int			cursor(t_shell *s, int *i, unsigned int key)
{
	if (key == K_HOME)
		while (*i)
		{
			*i -= 1;
			TC_MV_LEFT;
		}
	if (key == K_END && s->rcmd && s->lrcmd)
		while (*i < s->lrcmd)
		{
			*i += 1;
			TC_MV_RIGHT;
		}
	key == K_LEFT && s->rcmd && *i > 0 ? TC_MV_LEFT : 0;
	key == K_LEFT && s->rcmd && *i > 0 ? *i -= 1 : 0;
	key == K_RIGHT && s->rcmd && *i < s->lrcmd ? TC_MV_RIGHT : 0;
	key == K_RIGHT && s->rcmd && *i < s->lrcmd ? *i += 1 : 0;
	return (0);
}

/*
** TERMCAPS: Store the RAW commands with the additional character
*/

t_shell		*edit_rcmd(t_shell *s, int i, char *buffer)
{
	char	*tmp;
	int		j;
	int		sv;

	sv = i;
	j = 0;
	if (!s->rcmd && (s->rcmd = ft_strdup(buffer)))
		return (s);
	tmp = ft_strdup(s->rcmd);
	s->rcmd ? ft_memdel((void *)&s->rcmd) : (0);
	s->rcmd = ft_strnew(ft_strlen(tmp) + ft_strlen(buffer) + 1);
	ft_strncpy(s->rcmd, tmp, i);
	while (buffer[j] != '\0')
		s->rcmd[sv++] = buffer[j++];
	while (tmp[i] != '\0')
		s->rcmd[sv++] = tmp[i++];
	s->rcmd[sv] = '\0';
	s->lrcmd = ft_strlen(s->rcmd);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (s);
}

/*
** TERMCAPS: Handle the - DEL and RETURN - key and propelly delete it from rcmd
*/

t_shell		*del_rcmd(t_shell *s, int i, int key, int *r_i)
{
	char	*tmp;
	int		sv;

	if ((key == K_DEL) || (key == K_RETURN))
	{
		(key == K_DEL) ? TC_DELETE : (0);
		(key == K_RETURN) ? TC_MV_LEFT : (0);
		(key == K_RETURN) ? TC_DELETE : (0);
		(key == K_RETURN) ? (*r_i -= 1) : (0);
	}
	sv = i - 1;
	tmp = ft_strdup(s->rcmd);
	s->rcmd ? ft_memdel((void *)&s->rcmd) : (0);
	s->rcmd = ft_strnew(ft_strlen(tmp));
	ft_strncpy(s->rcmd, tmp, i);
	while (tmp[i] != '\0')
		s->rcmd[sv++] = tmp[i++];
	s->rcmd[sv] = '\0';
	tmp ? ft_memdel((void *)&tmp) : (0);
	s->lrcmd = ft_strlen(s->rcmd);
	(!s->lrcmd) ? (ft_memdel((void *)&s->rcmd)) : (0);
	return (s);
}
