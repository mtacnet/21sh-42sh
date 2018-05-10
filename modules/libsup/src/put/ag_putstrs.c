/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_putstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:43:38 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:43:40 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_putstrs.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Affichage d'une chaîne de caractères suivie d'un espace
*/

#include "libag.h"

/*
**	\brief Affichage d'une chaîne de caractères suivie d'une espace
**
**	\param	str	- chaîne de caractères
**
**	\return	**nombre de caractères** affichés
*/

int	ag_putstrs(char const *str)
{
	if (str)
		return (ft_putstr(str) + ft_putchar(' '));
	return (0);
}
