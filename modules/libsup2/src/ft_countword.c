/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:45:10 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:45:13 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmt.h"

int		ft_countword(const char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			j++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}
