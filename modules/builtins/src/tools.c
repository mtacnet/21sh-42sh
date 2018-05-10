/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:30:37 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:30:38 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*clear_x_path(char *path, int where, int len)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (where)
		tmp = ft_strsub(path, 0, where);
	if (ft_strlen(path) - (where + len + 1))
		tmp2 = ft_strsub(path, where + len, ft_strlen(path) - (where + len));
	if (path)
		ft_strdel(&path);
	if (!tmp2)
		return (tmp);
	if (!tmp)
		return (tmp2);
	if (!(path = ft_strnew(ft_strlen(tmp) + ft_strlen(tmp2))))
		return (NULL);
	path = ft_strcpy(path, tmp);
	path = ft_strcat(path, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (path);
}

int		dirty_path(char *path, int *where)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (path[i])
	{
		if (ft_strnequ(&path[i], "/../", 4) || ft_strequ(&path[i], "/.."))
		{
			while (i - ret && path[i - ret] == '/')
				ret++;
			while (i - ret && path[i - ret] != '/')
				ret++;
			*where = i - ret;
			return (ret + 3);
		}
		if (ft_strnequ(&path[i], "/./", 3) || ft_strequ(&path[i], "/."))
		{
			*where = i;
			return (2);
		}
		i++;
	}
	return (0);
}

char	*backslash_it(char *root_path, char *path, int c)
{
	char	*ret;

	if (!root_path)
	{
		if (!(ret = ft_strnew(ft_strlen(path) + 1)))
			return (NULL);
	}
	else if (!(ret = ft_strnew(ft_strlen(path) + ft_strlen(root_path) + 1)))
		return (NULL);
	if (root_path)
	{
		ret = ft_strcpy(ret, root_path);
		if (c > 0)
			ret[ft_strlen(ret)] = (char)c;
	}
	else if (c > 0)
		ret[0] = (char)c;
	if (ret && ret[0])
		ret = ft_strcat(ret, path);
	return (ret);
}

char	*clean_path(char *path)
{
	int		where;
	int		i;

	while ((i = dirty_path(path, &where)))
		path = clear_x_path(path, where, i);
	where = 1;
	while (path[where])
	{
		if (path[where - 1] == '/' && path[where] == '/')
		{
			i = 0;
			while (path[where + i] == '/')
				i++;
			path = clear_x_path(path, where - 1, i);
			where = 0;
		}
		where++;
	}
	if (path[0] != '/')
		path = backslash_it(NULL, path, '/');
	if (ft_strlen(path) > 1 && path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = '\0';
	return (path);
}
