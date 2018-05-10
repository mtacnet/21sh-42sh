/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:26 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:46:36 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

/*
**	\brief	Remplacement de la ligne actuelle par celle de l'historique
*/

static int	alter_line(char **line, t_line *line_info, char *new)
{
	int		i;

	if (line && line_info && new)
	{
		i = -1;
		ft_bzero(line[0], line_info->len);
		line_info->len = 0;
		line_info->cursor_i = 0;
		while (new[++i])
			if (!(insert_char(line, new[i], line_info)))
				line_info->len++;
		line_info->cursor_i = line_info->len;
		return (0);
	}
	return (1);
}

/*
**	\brief	Suppression du sigleton de get_save()
*/

void		delete_save(void)
{
	char	**tmp;

	if ((tmp = get_save(NULL)))
		ft_strdel(tmp);
}

/*
**	\brief	Pointeur sur la chaîne de la commande en cours d'édition
**
**	Pour initialiser le sigleton, l'appel devra s'effectuer en donnant le
**	pointeur de la chaîne de caractères en paramètre de la fonction.
**	Pour simplement récupérer le pointeur sur la chaîne, le paramètre `line`
**	devra être `NULL`
*/

char		**get_save(char **line)
{
	static char	**save_save = NULL;

	if (line)
		save_save = line;
	return (save_save);
}

/*
**	\brief	Navigation dans l'historique
**
**	L'utilisateur peut naviguer dans l'historique avec `ctrl`-`n`/`bas` ou
**	`ctrl`-`p`/`haut` et éditer la ligne qu'il désire. L'historique en lui-même
**	n'est pas modifié.
**
**	\param	line -		ligne de commande
**	\param	m -			direction dans l'historique
**	\param	line_info -	structure contenant les informations nécessaires à
**						*line_input*.
**	\param	history -	historique des commandes
*/

int			manage_history(char **line, char m, t_line *line_info,
															t_lstag *history)
{
	static t_lstag	*list = NULL;
	static char		*l = NULL;

	if (history && line && line_info)
	{
		if ((!l || !list) && line)
		{
			delete_save();
			if (!(l = ft_strdup(*line)))
				return (sh_error_int(1, "in function manage_history"));
			get_save(&l);
		}
		if (!list && m == 65)
			list = history;
		else if (m == 65 && list && list->next)
			list = list->next;
		else if (m == 66 && list)
			list = list->prev;
		else
			return (1);
		return (alter_line(line, line_info, list ? list->content : l));
	}
	if (!history)
		list = NULL;
	return (1);
}
