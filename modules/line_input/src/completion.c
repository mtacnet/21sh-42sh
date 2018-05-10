/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:11 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:46:14 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

static void	insert_part(char **line, char *word, char *insert, t_line *info)
{
	int	i;
	int	e;

	info->cursor_i = find_end((const char*)line[0], info->cursor_i);
	e = info->cursor_i;
	i = 0;
	while (--e >= 0 && line[0][e] != '/' && (line[0][e] != ' ' ||
			(e > 0 && line[0][e] == ' ' && line[0][e - 1] == '\\')))
		i++;
	info->cursor_i = e + i + 1;
	if (word[0] == '$')
		i--;
	while (i >= 0 && insert[i])
		insert_char(line, insert[i++], info);
	if (insert[0] && insert[i - 1] != '/')
		insert_char(line, ' ', info);
}

static void	choice(char **line, t_line *info, char **ret)
{
	int i;

	i = -1;
	while (ret[++i])
		ret[i] = insert_backslash(ret[i]);
	i = nb_line(info->len, info->win_col);
	while ((size_t)i-- > info->cursor_y)
		ft_putstr(tgetstr("do", NULL));
	ft_putendl("");
	ag_putchoice((const char**)ret);
	ag_putstrs(get_prompt(NULL));
	ft_putstr(*line);
	replace_cursor(*info);
}

static int	complete_line2(char **line, t_line *info, char **word, char **dpath)
{
	int		val;
	char	**ret;

	val = 1;
	if ((ret = completion(word[0][0] == '$' ? &word[0][1] : word[0],
		word[0][0] == '$' ? NULL :
		(const char **)dpath, first_word(*line, info->cursor_i) ?
			(const char**)get_builtin(NULL) : NULL,
		word[0][0] == '$' ? (const char**)get_environ(NULL) : NULL)))
	{
		if (ret[0] && !ret[1])
		{
			ret[0] = insert_backslash(ret[0]);
			*word = insert_backslash(*word);
			insert_part(line, *word, ret[0], info);
			val = 0;
		}
		else
			choice(line, info, ret);
		ag_strdeldouble(&ret);
	}
	return (val);
}

/*
**	\brief	Complétion de la ligne de commande
**
**	\param	line	- ligne de commande
**	\param	info	- structure contenant les informations nécessaires à
**					*line_input*
**
**	\return	**0** en cas de succès et que la ligne doit être réaffichée,
**			ou **1** sinon
*/

int			complete_line(char **line, t_line *info)
{
	int		val;
	char	*part;
	char	*path;
	char	*word;
	char	**dpath;

	val = 1;
	if (line && info
		&& (part = cut_command((const char*)*line, info->cursor_i)))
	{
		word = NULL;
		path = NULL;
		if (!cut_path_word(part, &path, &word) && word)
		{
			if ((dpath = find_path(*line, path ? &path : NULL, &word, info)))
			{
				val = complete_line2(line, info, &word, dpath);
				ag_strdeldouble(&dpath);
			}
			ft_strdel(&word);
		}
		path ? ft_strdel(&path) : NULL;
		ft_strdel(&part);
	}
	return (val);
}
