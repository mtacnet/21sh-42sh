/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:27:19 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:27:20 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**	\brief	Obtention des variables locales
**
**	_Sigleton_ permettant d'obtenir et de mettre à jour le pointeur sur les
**	variables locales.
**	La fonction doit être appelée une première fois avec `loc` non nul afin
**	d'initialiser le sigleton. Les appels suivants peuvent être effectués avec
**	`loc` nul pour seulement obtenir le pointeur,
**	ou non nul pour le mettre à jour
**
**	\param	loc	- pointeur sur la tête de liste
**
**	\return	pointeur sur les **locales** ou **NULL**
**			si celui-ci n'existe pas ou que le pointeur n'a pas été initialisé
*/

char			***get_loc(char ***loc)
{
	static char	***l = NULL;

	if (loc)
		l = loc;
	return (l);
}

static void		check_content(char ***loc)
{
	if (loc && ft_vcontenv("PS1", "$>", loc))
		sh_error_exit(1, "in function create_loc");
	if (loc && ft_vcontenv("PS2", ">", loc))
		sh_error_exit(1, "in function create_loc");
	if (loc && ft_vcontenv("?", "0", loc))
		sh_error_exit(1, "in function create_loc");
}

/*
**	\brief	Création des variables locales
**
**	La fonction créée le tableau de variables locales contenant :
**	- HISTFILE : chemin vers le fichier d'historique. L'historique est placé
**				 à la racine du dossier de l'utilisateur
**
**	\param	env	- environnement, utilisé pour récuper la variable "HOME"
**
**	\return	**variables locales** ou **NULL** en cas d'erreur
*/

char			**create_loc(const char **env)
{
	char		**loc;
	char		*tmp;
	char		*home;

	if ((loc = (char**)ft_memalloc(sizeof(char*) * 2)))
	{
		if ((home = ft_getenv("HOME", env)) && home[0])
		{
			if ((tmp = ft_strnew(ft_strlen(home) + 14)))
			{
				tmp = ft_strcpy(tmp, home);
				tmp = ft_strcat(tmp, "/.21sh_history");
				if (ft_vcontenv("HISTFILE", tmp, &loc))
					sh_error_exit(1, "in function create_loc");
			}
			else
				ag_strdeldouble(&loc);
			tmp ? ft_strdel(&tmp) : sh_error_exit(1, "in function create_loc");
		}
		check_content(&loc);
	}
	else
		sh_error_exit(1, "in function create_loc");
	return (loc);
}
