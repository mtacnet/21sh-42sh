/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:38:23 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:38:25 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

/*
**	\brief	Obtention de l'historique
**
**	_Sigleton_ permettant d'obtenir et de mettre à jour le pointeur sur la tête
**	de liste de l'historique.
**	La fonction doit être appelée une première fois avec `history` non nul afin
**	d'initialiser le sigleton. Les appels suivants peuvent être effectués avec
**	`history` nul pour seulement obtenir le pointeur,
**	ou non nul pour le mettre à jour
**
**	\param	history	- pointeur sur la tête de liste
**
**	\return	**tête de liste** de l'historique ou **NULL** si celui-ci n'existe
** pas ou que le pointeur n'a pas été initialisé
*/

t_lstag		**get_history(t_lstag **history)
{
	static t_lstag	**h = NULL;

	if (history)
		h = history;
	return (h);
}
