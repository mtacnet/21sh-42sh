/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:45 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:46:47 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

char	*verif_path(char *path)
{
	char	*new;
	char	*home;

	if (ft_strnequ(path, "~/", 2))
		if ((home = ft_getenv("HOME", (const char**)get_environ(NULL))))
		{
			if ((new = ft_strnew(ft_strlen(home) + ft_strlen(&path[1]))))
			{
				new = ft_strcpy(new, home);
				new = ft_strcat(new, &path[1]);
				ft_strdel(&path);
				path = new;
			}
			else
			{
				ft_putendl_fd("", 2);
				sh_error(1, "in function line input: verif_path");
			}
		}
	return (path);
}

int		first_word(const char *line, int pos)
{
	int	i;
	int	ret;

	ret = -1;
	if (line)
	{
		ret = 1;
		i = find_begin(line, pos);
		while (--i >= 0 && ag_isspace(line[i]))
			NULL;
		if (i <= 0)
			ret = 1;
		else if (is_shellop(line[i]))
		{
			ret = 1;
			if (line[i] == '>' || line[i] == '<'
				|| (line[i] == '|' && line[i - 1] == '>'))
				ret = 0;
		}
		else
			ret = 0;
	}
	return (ret);
}

/*
**	Recherche le path pour la complétion, on fonction de la position du curseur
**	dans la ligne
*/

char	**find_path(char *line, char **path, char **word, t_line *info)
{
	char	*env;
	char	**dpath;

	dpath = NULL;
	path ? delete_backslash(*path) : NULL;
	word ? delete_backslash(*word) : NULL;
	if (!path)
	{
		if (first_word((const char*)line, info->cursor_i))
			env = ft_getenv("PATH", (const char**)get_environ(NULL));
		else
			env = "./";
		if (env && !(dpath = ft_strsplit(env, ':')))
			sh_error_exit(1, "in find_path function");
	}
	else
	{
		*path = verif_path(*path);
		if (*path && !(dpath = ft_strsplit(*path, ':')))
			sh_error_exit(1, "in find_path function");
	}
	return (dpath);
}
