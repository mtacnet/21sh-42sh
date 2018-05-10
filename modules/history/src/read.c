/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:38:11 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:38:16 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	read.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Lecture du fichier d'historique
*/

#include "history.h"

/*
**	\brief	Lecture du fichier d'historique
**
**	La fonction lit le fichier d'historique du fichier donné en paramètre
**	et retourne une liste créée à partir de celui-ci.
**	Chaque maillon de la liste contient une ligne de commande.
**
**	\param	path	- chemin d'accès au fichier
**	\param	history	- historique déjà existant (ou `NULL`)
**
**	\return	**liste** contenant l'historique des commandes ou **NULL** en cas
**			d'erreur.
*/

t_lstag			*read_history(char *path, t_lstag *history)
{
	int		fd;
	int		i;
	char	*line;
	t_lstag	*h;

	fd = open_history(path);
	h = history;
	line = NULL;
	i = 0;
	if (fd >= 0)
	{
		while (get_next_line(fd, &line) > 0 && i < 200000)
		{
			i++;
			h = add_history_lst(h, line);
			if (line)
				ft_strdel(&line);
		}
		line ? ft_strdel(&line) : NULL;
		if (i >= 200000)
			ft_putendl_fd("history: the file is too big. Calm down please.", 2);
		h ? cut_history(h, NULL) : 0;
		close(fd);
	}
	return (h);
}
