/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:20 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:46:22 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

/*
**	\brief	Insertion d'un caractère dans une chaîne
**
**	\return	**0** si l'insertion s'est effectuée correctement ou **1** sinon.
**			L'ajout peut échouer si `line` est `NULL` ou que sa taille est trop
**			grande (262144 caractères), ou que le caractère donné n'est pas
**			affichable.
*/

int			insert_char(char **line, char c, t_line *line_info)
{
	if (line && *line && line_info && line_info->size && (c >= 32 && c <= 126)
		&& line_info->len < MAX_ALLOC - 1)
	{
		if (line_info->len >= line_info->size - 1)
		{
			if (!(*line = (char*)ag_memrealloc(*line, line_info->size,\
										line_info->size + INPUT_BUF_SIZE)))
			{
				line_info->size = 0;
				ft_putendl_fd("", 2);
				return (sh_error_int(1, "in function line_input: insert_char"));
			}
			line_info->size += INPUT_BUF_SIZE;
		}
		if (line_info->cursor_i <= line_info->len)
			ft_memmove(&line[0][line_info->cursor_i + 1],\
						&line[0][line_info->cursor_i],\
						line_info->size - 1 - line_info->cursor_i);
		line[0][line_info->cursor_i++] = c;
		return (0);
	}
	return (1);
}

/*
**	\brief	Suppression d'un caractère dans une chaîne
**
**	\return	**0** si la suppression s'est effectuée correctement ou **1** sinon.
*/

int			delete_char(char **line, char t, t_line *line_info)
{
	if (line && *line && line_info && line_info->size && line_info->len > 0)
	{
		if ((t == 127 || t == 8) && line_info->cursor_i > 0)
		{
			ft_memmove(&line[0][line_info->cursor_i - 1],\
						&line[0][line_info->cursor_i],\
						line_info->len - line_info->cursor_i + 1);
			line_info->cursor_i--;
		}
		else if ((t == 27 || t == 4) && line_info->cursor_i < line_info->len)
			ft_memmove(&line[0][line_info->cursor_i],\
						&line[0][line_info->cursor_i + 1],\
						line_info->len - line_info->cursor_i);
		else
			return (1);
		return (0);
	}
	return (1);
}

/*
**	\brief	Échange de la position de deux caractère
**
**	Fonction pour la gestion de `ctrl`-`t.`
**
**	\param	line		- ligne de commande
**	\param	line_info	- structure contenant les informations nécessaires à
**						*line_input*.
*/

int			swap_char(char **line, t_line *line_info)
{
	char	c;

	if (line && line_info && line_info->cursor_i > 0)
	{
		if (line_info->cursor_i == line_info->len)
			line_info->cursor_i--;
		c = line[0][line_info->cursor_i];
		line[0][line_info->cursor_i] = line[0][line_info->cursor_i - 1];
		line[0][line_info->cursor_i - 1] = c;
		line_info->cursor_i++;
		return (0);
	}
	return (1);
}
