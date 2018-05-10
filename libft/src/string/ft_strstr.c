/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:23:07 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:23:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(const char *big, const char *little)
{
	int	i;

	i = 0;
	while (little[i])
	{
		if (little[i] != big[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strstr(const char *big, const char *little)
{
	int		j;
	int		find;

	if (!ft_strlen((char*)little))
		return ((char*)big);
	j = 0;
	find = 0;
	while (find == 0 && big[j])
	{
		find = ft_cmp(&big[j], little);
		if (!find)
			j++;
	}
	if (find)
		return ((char*)&big[j]);
	return (NULL);
}
