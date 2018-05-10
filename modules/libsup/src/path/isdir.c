/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:42:48 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:42:49 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	isdir.c
**	\author	Alexis Guérin
**	\date	7 février 2018
**
**	\brief	Test sur un chemin d'accès
*/

#include "libag.h"

/*
**	\brief	Test sur un chemin d'accès
**
**	La fonction teste si le chemin d'accès pointe sur un dossier ou non.
**	`stat` est utilisée, si le `path` donné pointe sur un lien symbolique, la
**	fonction renverra donc _1_ si celui-ci pointe vers un dossier.
**
**	\param	path	- chemin d'accès vers l'élément
**
**	\return	**1** si l'élément est un dossier ou **0** sinon
*/

int	isdir(const char *path)
{
	struct stat s;

	s.st_mode = 0;
	if (stat(path, &s))
		return (0);
	return (S_ISDIR(s.st_mode));
}
