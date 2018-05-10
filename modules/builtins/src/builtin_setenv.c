/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:30:16 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:30:17 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_there_dollar(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '$' && (str[i + 1] == '=' || !str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int			builtin_setenv(char **av, char ***env, char ***loc)
{
	int		i;
	int		m;
	int		ret;

	ret = 0;
	m = 0;
	i = 0;
	while (av[i])
	{
		if (!is_there_dollar(av[i]))
		{
			if ((m = find_var((const char *)av[i],
				(const char **)*loc, 0)) >= 0 && !ft_strchr(av[i], '='))
				ft_setenv(loc[0][m], env) && !ret ? ret = 1 : 0;
			else
				ft_setenv(av[i], env) && !ret ? ret = 1 : 0;
		}
		else
		{
			ret = 1;
			ft_putendl_fd("ERROR: invalid id", 2);
		}
		i++;
	}
	return (ret);
}
