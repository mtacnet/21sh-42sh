/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:27:25 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:27:26 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	is_that(char *line, char c)
{
	if (!c && (line[0] == '\'' || line[0] == '\"' || line[0] == '`'))
		return (line[0]);
	else if (!c && line[0] == '\\' && !line[1])
		return (line[0]);
	else if ((line[0] == '&' || line[0] == '|') && (!line[1] ||
				!not_empty(&line[1])))
		return (line[0]);
	else if (c && (c == line[0]))
		return (0);
	return (c);
}

/*
**	\brief	Détection de quotes ouvertes ou de backslash en fin de ligne
**
**	Regarde dans la ligne si des `quotes` (simples ou doubles ou back)
**	sont ouvertes et non fermées ou si un `backslash` est présent en fin
**	de ligne. Si oui, elle renvoie le **code ASCII du caractère** correspondant,
**	ou **0** sinon.
**
**	\param	line	- pointeur sur la ligne à regarder
**
**	\return	**0** la ligne ne sera pas en attente d'être complétée ou **le code
**			ASCII** du caractère ouvrant l'attente,
**			ou **-1** en cas d'erreur.
*/

int			quotes(char **line, char c)
{
	int	i;

	i = -1;
	if (c == '\\')
		c = 0;
	if (line && line[0])
	{
		if (*line[0] && (c == '&' || c == '|'))
			c = 0;
		while (line[0][++i])
		{
			c = is_that(&line[0][i], c);
			if (c == '&' && (((i > 0 && line[0][i - 1] != '&') || i == 0) &&
						(line[0][i + 1] != '&')))
				c = 0;
		}
	}
	else
		return (-1);
	return (c);
}
