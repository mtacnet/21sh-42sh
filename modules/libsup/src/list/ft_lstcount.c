/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:40:58 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:41:02 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ft_lstcount.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Test sur les éléments d'une liste
*/

#include "libag.h"

/*
**	\brief	Test sur les éléments d'une liste
**
**	Renvoie 1 si au moins un élément de la liste passé à la fonction
**	f renvoie 1.
**
**	\param	list	- tête de liste
**	\param	f		- fonction à appliquer sur les maillons
**
**	\return **1** si au moins un maillon valide la/les condition testée par f
**			ou **0** sinon
*/

int	ft_lstany(t_list *list, int f(void *))
{
	if (f)
		while (list)
		{
			if (f(list->content))
				return (1);
			list = list->next;
		}
	return (0);
}

/*
**	\brief	Compte le nombre de maillon
**
**	La fonction renvoie le nombre de maillon présent dans la liste.
**
**	\param	list	- tête de liste
**
**	\return	**nombre de maillon** dans la liste
*/

int	ft_lstcount(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

/*
**	\brief	Renvoie le total des retours de la fonction _f_
**
**	La fonction appelle la fonction _f_ (en lui donnant en paramètre le champ
**	_content_ de la structure _lst_) sur chaque maillon de la liste et retourne
**	la somme totale des retours de la fonction _f_.
**
**	\param	lst	- tête de liste
**	\param	f	- fonction à appliquer sur les maillons
**
**	\return	**total** des retours de la fonction `f` appliquée sur chaque
**			maillon
*/

int	ft_lstcount_all(t_list *lst, int f(void*))
{
	int	tot;

	tot = 0;
	while (lst)
	{
		if (lst->content)
			tot += f(lst->content);
		lst = lst->next;
	}
	return (tot);
}

/*
**	\brief	Renvoie le nombre de maillon _vrai_
**
**	La fonction appelle la fonction _f_ (en lui donnant en paramètre le champ
**	_content_ de la structure _lst_) sur chaque maillon de la liste et retourne
**	le nombre de maillon validant les conditions testées par `f`.
**
**	\param	list	- tête de liste
**	\param	f	- fonction à appliquer sur les maillons
**
**	\return	**nombre de maillons** validant les conditions de `f`
*/

int	ft_lstcount_if(t_list *list, int f(void*))
{
	int	i;

	i = 0;
	if (f)
		while (list)
		{
			if (f(list->content))
				i++;
			list = list->next;
		}
	return (i);
}
