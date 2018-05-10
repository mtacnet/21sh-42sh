/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddalpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:40:54 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:40:56 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ft_lstaddalpha.c
**	\author	Alexis Guérin
**	\date	9 février 2018
**
**	\brief	Fonction de tri par insertion
*/

#include "libag.h"

/*
**	\brief	Ajout trié dans une liste
**
**	ft_lstaddalpha() ajoute un élément `new` dans la liste `alst` en respectant
**	l'ordre ASCII (du champ `content` de t_list) et renvoie la tête de liste.
**	La fonction renvoie `NULL` si `new` est nul.
**
**	\param	alst	- pointeur sur la tête de liste
**	\param	new		- maillon à ajouter
**
**	\return	**tête de liste** ou **NULL** en cas d'erreur
*/

t_list	*ft_lstaddalpha(t_list **alst, t_list *new)
{
	t_list	*lst;
	t_list	*prev;
	t_list	*head;

	if (new)
	{
		head = *alst;
		lst = *alst;
		prev = NULL;
		if (!lst)
			return (new);
		while (lst && (ft_strcmp(new->content, lst->content) > 0))
		{
			prev = lst;
			lst = lst->next;
		}
		if (prev)
			prev->next = new;
		else
			head = new;
		new->next = lst;
		return (head);
	}
	return (NULL);
}
