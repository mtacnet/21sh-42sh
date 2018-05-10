/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:40:35 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:40:36 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_lstdel.c
**	\author	Alexis Guérin
**	\date	30 janvier 2019
**
**	\brief	Suppression d'une liste
*/

#include "libag.h"

/*
**	\brief	Suppression d'une liste
**
**	La fonction supprime la liste `alst` et libère la mémoire en faisant appel à
**	la fonction `del` sur chaque maillon.
**
**	ag_lstdelone() est appelé sur chaque maillon de la liste.
**
**	\param	alst	- pointeur sur la tête de liste à supprimer
**	\param	del		- fonction de suppression du champ `content`
*/

void	ag_lstdel(t_lstag **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		ag_lstdel(&((*alst)->next), del);
		ag_lstdelone(&(*alst), del);
	}
}
