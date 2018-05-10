/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:40:37 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:40:38 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_lstdelone.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Suppression d'un maillon
*/

#include "libag.h"

/*
**	\brief	Suppression d'un maillon
**
**	La fonction fait appel à `del` qui s'occupe de la suppression de la
**	libération de mémoire du champs `content` puis `ag_lstdelone` libère la
**	mémoire du maillon et met son pointeur à `NULL`.
**
**	\param	alst	- maillon à supprimer
**	\param	del		- fonction de suppression du champ content
*/

void	ag_lstdelone(t_lstag **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
