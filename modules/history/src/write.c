/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:38:27 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:38:33 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	write.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Écriture de l'historique dans le fichier
*/

#include "history.h"

/*
**	\brief	Écriture de l'historique dans le fichier
**
**	La fonction parcourt la liste contenant l'historique et écrit celui-ci
**	dans le fichier. La liste est parcourue du plus ancien maillon au plus
**	récent (de `prev` en `prev`).
**
**	\param	path	- chemin d'accès au fichier
**	\param	history	- maillon à partir duquel ajouter lire l'historique
*/

void	write_history(char *path, t_lstag *history)
{
	int	fd;

	if ((fd = open_history(path)) != -1)
	{
		while (history)
		{
			ft_putendl_fd(history->content, fd);
			history = history->prev;
		}
		close(fd);
	}
}
