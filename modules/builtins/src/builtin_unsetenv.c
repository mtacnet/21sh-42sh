/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:30:29 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:30:30 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int		builtin_unsetenv(char **av, char ***env)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (av && av[i])
		ft_unsetenv(av[i++], env) != 0 && !ret ? ret = 1 : 0;
	return (ret);
}
