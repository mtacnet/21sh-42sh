/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:29:44 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:29:45 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	set_new_pwd(char ***env, char *old, char *new, char ***local)
{
	if (ft_vcontenv("OLDPWD", old, env))
		return (1);
	if (ft_vcontenv("PWD", new, env))
		return (1);
	if (ft_vcontenv("PWD", new, local))
		return (1);
	beacon_pwd(new);
	return (0);
}

static char	*get_linked_dir(char *path, char option, char *curpath)
{
	char		*ret;
	char		*lnk;

	lnk = NULL;
	if (!(lnk = ft_strnew(PATH_MAX)))
		return (sh_error(1, "cd"));
	if (path[0] != '/')
		ret = backslash_it(curpath, path, '/');
	else
		ret = ft_strdup(path);
	ret = clean_path(ret);
	if (option == 'P' && readlink(ret, lnk, PATH_MAX) != -1)
	{
		if (lnk[0] != '/')
			lnk = remove_last_dir(ret, lnk);
		lnk = clean_path(lnk);
		return (lnk);
	}
	if (lnk)
		ft_strdel(&lnk);
	return (ret);
}

static	int	return_free(char *p, char *path)
{
	if (access(path, F_OK))
		error_message("ERROR: no such file or directory: ", path);
	else if (access(path, R_OK))
		error_message("ERROR: permission denied: ", path);
	else
		error_message("ERROR: not a directory: ", path);
	if (p)
		ft_strdel(&p);
	return (-1);
}

static int	ch_dir(char ***env, char *path, char option, char ***local)
{
	DIR		*test;
	char	*p;

	test = opendir(path);
	if (!(p = get_linked_dir(path, option, beacon_pwd(NULL))))
		return (-1);
	if (!access(p, F_OK | R_OK) && test)
	{
		if (chdir(p) == -1)
			return (sh_error_int(6, "cd"));
		set_new_pwd(env, beacon_pwd(NULL), p, local);
		closedir(test);
	}
	else
		return (return_free(p, path));
	ft_strdel(&p);
	return (0);
}

int			builtin_cd(char ***env, char **args, char ***loc)
{
	int		i;
	char	op;

	op = 'L';
	i = 0;
	while (args && args[i] && (ft_strequ(args[i], "-L") ||
		ft_strequ(args[i], "-P")))
		op = args[i++][1];
	if (args && args[i] && ft_strequ("-", args[i]))
	{
		if (ft_getenv("OLDPWD", (const char **)*env))
			return (ch_dir(env, ft_getenv("OLDPWD",
				(const char **)*env), op, loc));
		else
			return (sh_error_int(14, "cd"));
	}
	else if (args && !args[i])
	{
		if (ft_getenv("HOME", (const char **)*env))
			return (ch_dir(env, ft_getenv("HOME",
				(const char **)*env), op, loc));
		else
			return (sh_error_int(15, "cd"));
	}
	return (ch_dir(env, args[i], op, loc));
}
