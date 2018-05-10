/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:40:48 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:40:50 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_lstnew.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Création d'un maillon
*/

#include "libag.h"

/*
**	\brief	Création d'un maillon
**
**	La fonction alloue la taille nécessaire pour un maillon de la liste
**	[t_lstag][] ainsi que pour ses champs.
**	`content` et `content_size` sont copiés dans les champs correspondants et
**	`prev` et `next` sont initalisés à `NULL`.
**
**	[t_lstag]: structs__lstag.html
**
**	\param	content	- 		variable à stocker
**	\param	content_size -	taille nécessaire au stockage de la variable
**
**	\return	**maillon alloué** ou **NULL** en cas d'erreur
*/

t_lstag	*ag_lstnew(void const *content, size_t content_size)
{
	t_lstag	*list;

	if ((list = (t_lstag*)ft_memalloc(sizeof(t_lstag))))
	{
		if (!content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			if (!(list->content = ft_memalloc(sizeof(content) * content_size)))
			{
				free(list);
				return (NULL);
			}
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		list->prev = NULL;
		list->next = NULL;
	}
	return (list);
}
