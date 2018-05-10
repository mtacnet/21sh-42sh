/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_edit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:58 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:47:00 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

/*
**	\brief	Optention ou sauvegarde du presse-papier
**
**	La fonction permet de sauvegarder une chaîne dans le presse-papier et de la
**	récupérer.
**	La variale le contenant est `static` et son contenu est donc toujours
**	accessible lors d'un autre appel à *line_input*.
**	Pour récupérer le contenu du presse-papier sans écraser celui-ci avec une
**	nouvelle valeur, l'appel doit être effectué comme ceci :
**
**		clipboard = get_clipboard(NULL, 0);
**
**	\param	content	- contenu à écrire dans le presse-papier
**	\param	del		- booléen, **1** pour libérer la mémoire du presse-papier
**					ou **0** pour simplement récupérer celui-ci
*/

char	*get_clipboard(char *content, int del)
{
	static char	*clipboard = NULL;

	if ((del || content) && clipboard)
		ft_strdel(&clipboard);
	if (content)
		clipboard = ft_strdup(content);
	return (clipboard);
}

/*
**	\brief	Collage de la précédente sélection
**
**	Insert la sélection précédemment copiée à l'emplacement du curseur. Si du
**	texte est sélectionné, celui-ci est remplacé.
**
**	\param	line		- ligne de commande
**	\param	line_info	- structure contenant les informations nécessaires à
**						*line_input*.
*/

int		paste_selection(char **line, t_line *line_info)
{
	int		i;
	char	*paste;

	if (line && *line && line_info && (paste = get_clipboard(NULL, 0)))
	{
		i = -1;
		delete_selection(line, line_info);
		while (paste[++i])
			if (!(insert_char(line, paste[i], line_info)))
				line_info->len++;
		return (0);
	}
	return (1);
}

/*
** \brief	Copie ou découpe de la ligne de commande
**
**	\param	line		- ligne de commande
**	\param	cut			- booléen pour indiquer si en plus de la copie
**						la fonction doit aussi couper la sélection
**	\param	line_info 	- informations sur la ligne de commande
**
**	\return	**1** si l'affichage n'as pas besoin d'être mis à jour (copie) ou
**			** 0** sinon.
*/

int		copy_cut_selection(char **line, int cut, t_line *line_info)
{
	int		i;
	int		s;
	char	*copy;

	if (line && *line && line_info && line_info->cursor_s >= 0)
	{
		i = (int)line_info->cursor_i;
		s = line_info->cursor_s;
		if (i > s)
			ag_swap(&i, &s);
		if (s == (int)line_info->len)
			s--;
		get_clipboard((copy = ft_strsub(*line, i, s - i + 1)), 0);
		if (copy)
			ft_strdel(&copy);
		if (cut)
			return (delete_selection(line, line_info));
	}
	return (1);
}

/*
**	\brief	Insertion d'un caractère à la place du ou des caratères sélectionnés
*/

int		insert_char_selection(char **line, char c, t_line *line_info)
{
	if (line && *line && line_info)
	{
		delete_selection(line, line_info);
		insert_char(line, c, line_info);
		return (0);
	}
	return (1);
}

/*
**	\brief	Suppression du ou des caractères sélectionnés
*/

int		delete_selection(char **line, t_line *line_info)
{
	int	tmp;

	if (line && *line && line_info && line_info->len
		&& line_info->cursor_s > -1)
	{
		if ((int)line_info->cursor_i > line_info->cursor_s)
		{
			tmp = (int)line_info->cursor_i;
			line_info->cursor_i = line_info->cursor_s;
			line_info->cursor_s = tmp;
		}
		while (line_info->cursor_s-- >= (int)line_info->cursor_i)
			delete_char(line, 4, line_info);
		return (0);
	}
	return (1);
}
