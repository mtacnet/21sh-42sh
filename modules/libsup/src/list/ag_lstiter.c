/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:40:42 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:40:43 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_lstiter.c
**	\author	Alexis Guérin
**	\date	31 janvier 2018
*/

#include "libag.h"

/*
**	\brief	Application de fonction sur une liste
**
**	ag_lstiter() applique la fonction `f` sur chaque maillon de la list `lst`.
**
**	\param	lst	- list
**	\param	f	- fonction à appliquer
*/

void	ag_lstiter(t_lstag *lst, void (*f)(t_lstag *elem))
{
	t_lstag	*lst1;

	lst1 = lst;
	while (lst1)
	{
		f(lst1);
		lst1 = lst1->next;
	}
}
