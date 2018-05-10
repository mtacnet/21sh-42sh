/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:30:05 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:30:06 by mtacnet          ###   ########.fr       */
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

int			builtin_set(char **av, char ***loc)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	if (av && av[i])
		while (av && av[i])
		{
			if (!is_there_dollar(av[i]))
				ft_setenv(av[i], loc) && !ret ? ret = 1 : 0;
			else
			{
				ret = 1;
				ft_putendl_fd("ERROR: invalid id", 2);
			}
			i++;
		}
	else
		print_env((const char **)*loc);
	return (ret);
}
