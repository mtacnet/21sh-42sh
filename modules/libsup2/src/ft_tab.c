/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:45:26 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:45:28 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmt.h"

void	supp_elem_tab(char **array, int value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i] && array[i][0] != '\0')
		i++;
	if (value >= i)
		return ;
	else
	{
		while (j < i)
		{
			array[j] = array[j + 1];
			j++;
		}
	}
	return ;
}

void	free_tab(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		if (array[i] != NULL)
		{
			ft_strdel(&(array[i]));
			i++;
		}
		else
			i++;
	}
	free(array);
	array = NULL;
}
