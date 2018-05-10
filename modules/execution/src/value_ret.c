/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_ret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:35:04 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:35:05 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexec.h"

void	set_value_ret(int value)
{
	char	***local;
	char	*tmp;

	if ((tmp = ft_itoa(value % 256)))
	{
		local = get_loc(NULL);
		if (ft_vcontenv("?", tmp, local))
			ft_putendl_fd("ERROR: couldn't change value of ?", 2);
		ft_strdel(&tmp);
	}
	else
		ft_putendl_fd("ERROR: couldn't change value of ?", 2);
}
