/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenvloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:33:22 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:33:23 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

/*
**	\brief	Recherche d'une variable dans les locales et dans l'environnement
**
**	La fonction cherche la variable dans l'environnement et dans les variables
**	locales.
**	Si la variable est présente dans les deux tableaux, la valeur de celle de
**	l'environnement est renvoyée.
**
**	\return	**valeur** de la variable ou **NULL** si elle n'existe pas
*/

char	*getenvloc(const char *name, const char **loc, const char **env)
{
	char	*value;

	value = NULL;
	if (!env || !(value = ft_getenv(name, env)))
		value = loc ? ft_getenv(name, loc) : NULL;
	return (value);
}
