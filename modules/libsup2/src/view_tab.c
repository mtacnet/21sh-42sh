/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:45:29 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:45:34 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmt.h"

void	view_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0] != '\0')
	{
		ft_putendl(tab[i]);
		i++;
	}
}
