/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:30:21 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:30:25 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		builtin_unset(char **av, char ***loc)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (av && av[i])
	{
		if (ft_strequ(av[i], "PS1") || ft_strequ(av[i], "PS2")
				|| ft_strequ(av[i], "?"))
		{
			ft_putstr_fd("ERROR: can't unset ", 2);
			ft_putendl_fd(av[i], 2);
			ret = -1;
		}
		else if (ft_strchr(av[i], '='))
		{
			ft_putstr_fd("ERROR: not a valid identifier: ", 2);
			ft_putendl_fd(av[i], 2);
			ret = -1;
		}
		else
			ft_unsetenv(av[i], loc) != 0 && !ret ? ret = 1 : 0;
		i++;
	}
	return (ret);
}
