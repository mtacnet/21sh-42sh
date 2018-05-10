/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:20:13 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:20:14 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la chaîne de caractères sur la sortie standard suivi d'un retour
** à la ligne.
*/

int	ft_putendl(char const *s)
{
	if (s)
		return (ft_putstr(s) + ft_putchar('\n'));
	return (0);
}
