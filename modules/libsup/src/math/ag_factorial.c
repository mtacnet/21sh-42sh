/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:41:16 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:41:19 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_factorial.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Calcul d'une factorielle
*/

/*
**	\brief	Calcul de la factorielle d'un nombre
**
**	Renvoie le résultat de `nb!`.
**
**	\param	nb	- nombre
**
**	\return	**factorielle** de `nb`
*/

int	ag_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
		return (nb * ag_factorial(nb - 1));
}
