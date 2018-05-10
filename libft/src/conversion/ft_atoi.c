/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:16:48 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:16:49 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') ||
		(c == '\f') || (c == '\r') || (c == ' '))
		return (1);
	return (0);
}

/*
** ft_atoi() prend en entrée une chaîne de caractères (censée représenter un
** nombre) et renvoie sa représentation en int.
*/

int			ft_atoi(const char *str)
{
	int i;
	int nb;
	int neg;

	nb = 0;
	i = 0;
	neg = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && str[i] <= 57 && str[i] != '\0')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (neg * nb);
}
