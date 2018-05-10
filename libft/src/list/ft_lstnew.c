/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:18:07 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:18:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_lstnew() alloue la mémoire pour un maillon t_list
** et y copie les paramètres donnés.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list*)malloc(sizeof(t_list))))
	{
		if (!content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			if (!(list->content = malloc(sizeof(content) * content_size)))
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
