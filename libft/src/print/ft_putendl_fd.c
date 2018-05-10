/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:20:40 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:20:42 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la chaîne de caractères sur le fd indiqué suivi d'un retourne
** à la ligne.
*/

int	ft_putendl_fd(char const *s, int fd)
{
	if (s)
		return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
	return (0);
}
