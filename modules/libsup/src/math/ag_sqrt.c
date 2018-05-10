/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:41:22 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:41:29 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_sqrt.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Calcul de la racine d'un nombre
*/

/*
**	\brief	Calcul de la racine d'un nombre
**
**	\param	nb	- nombre
**
**	\return	**racine** de `nb`
*/

int		ag_sqrt(int nb)
{
	int ope;

	ope = 2;
	if (nb == 1)
		return (1);
	else if (nb > 0)
	{
		while (ope * ope < nb)
			ope++;
		if (ope * ope == nb)
			return (ope);
	}
	return (0);
}
