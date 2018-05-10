/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:42:13 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:42:16 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_nbrlen.c
**	\author	Alexis Guérin
**	\date	2 février 2018
**
**	\brief	Calcul du nombre de longueur d'un nombre
*/

#include "libag.h"

/*
**	\brief	Calcul du nombre de longueur d'un nombre
**
**	La fonction renvoie le nombre de caractère nécessaires à l'affichage du
**	nombre `nb`, y compris de son signe si celui-ci est négatif.
**
**	\param	nb	- nombre
**
**	\return	**nombre de caractères** nécessaires à l'affichage
*/

int	ag_nbrlen(long nb)
{
	unsigned long	n;
	int				i;

	n = (nb < 0 ? -nb : nb);
	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return ((nb < 0 ? i + 1 : i));
}
