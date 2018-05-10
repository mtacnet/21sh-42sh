/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:30:41 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:30:42 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*concat_args(char **args)
{
	int		len;
	int		i;
	char	*ret;

	i = 0;
	len = 0;
	if (!args || !args[0])
		return (NULL);
	while (args[i])
		len += ft_strlen(args[i++]);
	len += ag_strlendouble(args) - 1;
	i = 0;
	if (!(ret = ft_strnew(len)))
		return (sh_error(1, "echo"));
	while (args[i])
	{
		ret = ft_strcat(ret, args[i]);
		if (args[i + 1])
			ret = ft_strcat(ret, " ");
		i++;
	}
	return (ret);
}

char	*remove_last_dir(char *path, char *new)
{
	int		i;
	int		where;

	where = ft_strlen(path) - 1;
	i = 0;
	while (path[where] != '/')
	{
		where--;
		i++;
	}
	if (i)
		path = clear_x_path(path, where, i);
	path = backslash_it(path, new, '/');
	return (path);
}

char	what_char_is_it(char *str, int *len)
{
	char	*tmp;
	char	ret;

	tmp = ft_strsub(str, 0, 3);
	*len = 4;
	if (ft_atoi(tmp) > 777)
	{
		ft_strdel(&tmp);
		tmp = ft_strsub(str, 0, 2);
		*len = 3;
	}
	ret = (char)from_base_atoi(tmp, 8);
	ft_strdel(&tmp);
	if (!ret)
		*len = 1;
	return (ret);
}
