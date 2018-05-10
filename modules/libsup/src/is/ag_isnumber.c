/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:40:08 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:40:10 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libag.h"

/*
**	\brief	Vérification de la représentation d'un nombre dans une chaîne
**
**	La fonction analyse la chaîne reçue et regarde si celle-ci peut représenter
**	un nombre entier (décimal).
**	Celui-ci peut être positif ou négatif et ne doit pas comporter d'espace.
**
**	Exemple :
**		- 1000	: valide
**		- -1994	: valide
**		- +963	: valide
**		- 1 000	: invalide
**		- - 99	: invalide
**
**	\param	str	- chaîne représentant le nombre
**
**	\return	**1** si la chaîne représente un nombre ou
**			**0** sinon
*/

int	ag_isnumber(const char *str)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
			if (!ft_isdigit(str[i]))
				if (!(i == 0 && (str[i] == '-' || str[i] == '+')))
					return (0);
		return (1);
	}
	return (0);
}
