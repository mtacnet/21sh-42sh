/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:46 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:47 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tok		*new_list(void)
{
	return (NULL);
}

int			is_empty(t_tok **lst)
{
	if ((*lst) == NULL)
		return (1);
	else
		return (0);
}

t_tok		*init_element(t_tok *element)
{
	if (!(element = (t_tok*)malloc(sizeof(t_tok))))
		return (sh_error(1, "function init_element"));
	element->token_id = 0;
	element->token = NULL;
	element->next = NULL;
	return (element);
}

void		freelst(t_tok **lst)
{
	t_tok		*list;
	t_tok		*tmp;

	list = (*lst);
	while (list)
	{
		tmp = list->next;
		ft_strdel(&(list->token));
		free(list);
		list = tmp;
	}
	(*lst) = NULL;
}
