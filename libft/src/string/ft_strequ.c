/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:21:54 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:21:55 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strequ() effectue la comparaison entre 's1' et 's2', si elles sont
** identiques, 1 est renvoyé, 0 sinon.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	int	size1;
	int	size2;
	int	i;

	if (!s1 || !s2)
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	i = 0;
	if (size1 != size2)
		return (0);
	while (i < size1)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
