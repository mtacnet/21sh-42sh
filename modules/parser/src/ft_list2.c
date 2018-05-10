/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:52 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:53 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		add_element(t_tok **element, char *token, int token_id, int id)
{
	(*element)->id = id;
	(*element)->token_id = token_id;
	(*element)->token = ft_strdup(token);
}

void			push_elemx(t_tok **lst, char *token, int token_id, int id)
{
	t_tok		*element;
	t_tok		*head;
	t_tok		*prev;

	element = NULL;
	element = init_element(element);
	add_element(&element, token, token_id, id);
	head = (*lst);
	prev = NULL;
	if (is_empty(lst))
	{
		(*lst) = element;
		return ;
	}
	while ((*lst) != NULL)
	{
		prev = (*lst);
		(*lst) = (*lst)->next;
	}
	if (prev)
		prev->next = element;
	else
		head = element;
	element->next = (*lst);
	(*lst) = head;
}
