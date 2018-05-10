/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:33:03 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:33:04 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

/*
**	\brief	Copie de l'environnement
**
**	La fonction alloue la mémoire nécessaire pour pouvoir copier l'environnement
**	et retourne cette copie.
**
**	\param	environment	- environnement à copier
**	\param	size		- taille de l'environmment
**
**	\return	**copie** de l'environnement ou **NULL** en cas d'erreur.
*/

char	**dupenv(const char **environment, int size)
{
	int		i;
	char	**copy;

	copy = NULL;
	if (environment && size > 0)
	{
		i = -1;
		if ((copy = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		{
			while (++i < size && copy)
				if (environment[i] && !(copy[i] = ft_strdup(environment[i])))
				{
					ag_strdeldouble(&copy);
					return (sh_error(1, "dupenv"));
				}
		}
		else
			return ((char**)sh_error_exit(1, "in dupenv function"));
	}
	return (copy);
}
