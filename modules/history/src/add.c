/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:37:47 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:37:51 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	add.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Ajout d'une ligne de commande à l'historique
*/

#include "history.h"

int			not_empty(char *line)
{
	while (*line)
	{
		if (!ag_isspace(line[0]))
			return (1);
		line++;
	}
	return (0);
}

static int	verif(t_lstag *node, char *line)
{
	if (node && line[0] && not_empty(line))
		return (1);
	return (0);
}

/*
**	\brief	Ajout d'une ligne de commande à l'historique
**
**	La fonction ajoute la ligne de commande reçue en début d'historique.
**	Si cette ligne est vide ou identique à la précédente,
**	elle n'est pas ajoutée.
**
**	\param	history	- pointeur sur la tête de liste
**	\param	line	- ligne de commande
**
**	\return	tête de liste de **historique** modifié (ou non)
**			ou **NULL** en cas d'erreur
*/

t_lstag		*add_history_lst(t_lstag *history, char *line)
{
	t_lstag	*node;

	node = NULL;
	if (line)
	{
		if (!(node = ag_lstnew(line, ft_strlen(line) + 1)))
			sh_error_exit(1, "in function history: add_history");
		if (verif(node, line))
		{
			if (history)
				ag_lstadd(&history, node);
			else
				history = node;
		}
		else if (node)
			delete_history_list(&node);
	}
	return (history);
}

/*
**	\brief	Suppression des retours à la ligne dans la commande
**
**	Les retours à la ligne sont remplacés par des espaces
*/

static void	clean_line(char *line)
{
	if (line)
		if (line[0] == '\n')
			line[0] = ' ';
}

/*
**	\brief	Ajout d'une commande dans le fichier et dans la liste
**
**	\param	history	- pointeur sur la tête de liste
**	\param	path	- chemin d'accès au fichier
**	\param	line	- ligne de commande
**
**	\return	tête de liste de **historique** modifié (ou non)
**			ou **NULL** en cas d'erreur
*/

t_lstag		*add_history(t_lstag *history, char *path, char *line)
{
	char	*tmp;

	if (line && (!history || !ft_strequ(history->content, line)))
	{
		tmp = NULL;
		if (ft_strchr(line, '\n'))
		{
			if (!(tmp = ft_strdup(line)))
			{
				sh_error(1, "in add_history function");
				return (history);
			}
			ft_striter(tmp, clean_line);
			line = tmp;
		}
		history = add_history_lst(history, line);
		write_history(path, history);
		cut_history(history, path);
		tmp ? ft_strdel(&tmp) : NULL;
	}
	return (history);
}
