/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:30:46 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:30:47 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char			*get_path(char *path)
{
	static char		*stock = NULL;

	if (path)
		stock = path;
	return (stock);
}

void			error_message(char *msg, char *msg2)
{
	ft_putstr_fd(msg, 2);
	if (msg2)
		ft_putendl_fd(msg2, 2);
	else
		ft_putstr_fd("\n", 2);
}

char			*beacon_pwd(char *str)
{
	static char		*pwd_pinned = NULL;

	if (str)
	{
		if (pwd_pinned)
			ft_strdel(&pwd_pinned);
		pwd_pinned = ft_strdup(str);
	}
	return (pwd_pinned);
}

int				from_base_atoi(const char *str, int base)
{
	int		res;
	int		i;
	int		neg;

	neg = 0;
	i = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f' \
			|| str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '0' + base && str[i] >= '0' && str[i])
	{
		res = res * base + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-res);
	return (res);
}
