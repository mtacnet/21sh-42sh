/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_strlendouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:44:07 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:44:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_strlendouble.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Longueur de la première dimension d'un tableau de caractères
*/

#include "libag.h"

/*
**	\brief	Longueur de la première dimension d'un tableau de caractères
**
**	Calcule la longueur de la première dimension d'un tableau de caractères.
**	Celle-ci doit être terminée par `\0`.
**
**	\param	doublestr	- tableau de chaîne de caractères
**
**	return	**longueur** de la première dimension
*/

int	ag_strlendouble(char **doublestr)
{
	int	i;

	i = 0;
	if (doublestr)
		while (doublestr[i])
			i++;
	return (i);
}
