/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:23 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:46:25 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

/*
** Indique à l'édition de ligne si on est ou non dans un heredoc
*/

int		is_in_heredoc(int i)
{
	static int	s = 0;

	if (i >= 0)
		s = i;
	return (s);
}

/*
**	Singleton contenant le delimiter du heredoc.
**
**	Lorsque l'utilisateur est dans un heredoc et appuie sur `ctrl-d`,
**	le delimiteur est écrit dans la ligne (si celle-ci était vide) et
**	l'édition de ligne retourne la commande
*/

char	*redoc_delimiter(char *str)
{
	static char	*s = NULL;

	if (str)
		s = str;
	return (s);
}
