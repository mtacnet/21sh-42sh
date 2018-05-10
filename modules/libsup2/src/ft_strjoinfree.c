/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:45:20 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:45:22 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmt.h"

char	*ft_strjoinfree(char *s1, char *s2, int mode)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (mode == 1 && s1)
		ft_strdel(&s1);
	else if (mode == 2 && s2)
		ft_strdel(&s2);
	else if (mode != 1 && mode != 2 && s1 && s2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (tmp);
}
