/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:27:10 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:27:11 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**	\brief	Obtention du nom du fichier d'historique
**
**	_Sigleton_ permettant d'obtenir et de mettre à jour le nom du fichier
**	d'historique.
**	La fonction doit être appelée une première fois avec `file` non nul afin
**	d'initialiser le sigleton. Les appels suivants peuvent être effectués avec
**	`file` nul pour seulement obtenir le pointeur,
**	ou non nul pour le mettre à jour
**
**	\param	file	- non du fichier d'historique
**
**	\return	**tête de liste** de l'historique ou **NULL**
**			si celui-ci n'existe pas ou que le pointeur n'a pas été initialisé
*/

char		*get_history_file(const char *file)
{
	static char	*f = NULL;

	if (file)
		f = (char*)file;
	else
	{
		if ((f = getenvloc("HISTFILE", (const char**)*get_loc(NULL),
						(const char**)*get_env(NULL))) && !f[0])
			f = NULL;
	}
	return (f);
}

/*
**	\brief	Initialisation du fichier d'historique et récupération
*/

t_lstag		*init_history(const char **env, const char **loc)
{
	t_lstag	*history;

	get_history_file(getenvloc("HISTFILE", loc, env));
	history = read_history(get_history_file(NULL), NULL);
	cut_history(history, get_history_file(NULL));
	return (history);
}
