/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:41:19 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:41:21 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_pow.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Calcul de la puissane d'un nombre
*/

#include "libag.h"

/*
**	\brief	Calcul de la puissance d'un nombre
**
**	Renvoie le résultat de `nb` à la puissance `power`.
**
**	\param	nb		- nombre
**	\param	power	- puissance
**
**	\return	**resultat** de `nb^power`
*/

long long int	ag_pow(int nb, unsigned int power)
{
	long long res;

	res = 1;
	while (power--)
		res = res * nb;
	return (res);
}
