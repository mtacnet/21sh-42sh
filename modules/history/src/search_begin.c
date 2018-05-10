/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_begin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:38:18 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:38:20 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	search_begin.c
**	\author	Alexis Guérin
**	\date	1 février 2018
*/

#include "history.h"

static int		verif(t_lstag *new, t_lstag *lst)
{
	t_lstag	*tailnew;

	tailnew = ag_lsttail(new);
	if (!tailnew || !ft_strequ(lst->content, tailnew->content))
		return (1);
	return (0);
}

static t_lstag	*search(t_lstag *lst, char *command)
{
	t_lstag	*new_list;
	t_lstag	*new_elem;

	new_list = NULL;
	while (lst)
	{
		if (ft_strnequ(lst->content, command, ft_strlen(command))
			&& verif(new_list, lst))
		{
			new_elem = ag_lstnew(lst->content, lst->content_size);
			if (!new_list)
				new_list = new_elem;
			else
				ag_lstaddtail(&new_list, new_elem);
		}
		lst = lst->next;
	}
	return (new_list);
}

/*
**	\brief	Recherche de commande
**
**	Renvoie une liste composée des commandes identiques ou dont le début
**	est identique à la chaîne envoyée.
**
**	\param	history	- historique
**	\param	command	- commande à rechercher
**
**	\return	**liste** composée des commandes pouvant correspondre ou
**			**NULL** en cas d'erreur
*/

t_lstag			*search_history_begin(t_lstag *history, char *command)
{
	t_lstag	*list;

	list = NULL;
	if (command)
		list = search(history, command);
	return (list);
}
