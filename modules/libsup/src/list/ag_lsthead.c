/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_lsthead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:40:39 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:40:41 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_lsthead.c
**	\author	Alexis Guérin
**	\date	8 mars 2018
*/

#include "libag.h"

/*
**	\brief	Renvoie la tête de liste
**
**	La fonction parcourt la liste et renvoie le premier maillon.
**
**	\param	list	- liste
**
**	\return	pointeur sur la **tête de la liste** ou **NULL** en cas d'erreur
*/

t_lstag	*ag_lsthead(t_lstag *list)
{
	while (list && list->prev)
		list = list->prev;
	return (list);
}
