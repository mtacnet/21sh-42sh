/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_lstmapif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:40:44 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:40:47 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\brief	ag_lstmapif.c
**	\author	Alexis Guérin
**	\date	1 février 2018
*/

#include "libag.h"

/*
**	\brief	Création d'une liste à partir d'une sélection
**
**	La fonction applique `f` sur chaque maillon de la list `lst`. Une nouvelle
**	liste est créée à partir des maillons qui, envoyé à `f`, renvoyaient _vrai_.
**	La fonction `add` est utilisée pour l'insertion de chaque maillon dans la
**	nouvelle liste.
*/

t_lstag		*ag_lstmapif(t_lstag *lst, int (*f)(t_lstag*),
											void (add)(t_lstag**, t_lstag*))
{
	t_lstag	*new_list;
	t_lstag	*new_elem;

	new_list = NULL;
	while (lst)
	{
		if (f(lst))
		{
			new_elem = ag_lstnew(lst->content, sizeof(lst->content));
			if (!new_list)
				new_list = new_elem;
			else
				add(&new_list, new_elem);
		}
		lst = lst->next;
	}
	return (new_list);
}
