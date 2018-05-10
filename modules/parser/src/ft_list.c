/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:48 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:49 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	push_elem(t_tok **lst, char *token)
{
	t_tok		*element;
	t_tok		*head;
	t_tok		*prev;

	element = NULL;
	element = init_element(element);
	element->token = ft_strdup(token);
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

void	supp_elem(t_tok **lst, char *arg)
{
	size_t		i;
	t_tok		*tmp;
	t_tok		*prev;

	i = 0;
	tmp = (*lst);
	prev = NULL;
	i = ft_strlen(arg);
	if (tmp != NULL && ft_strncmp(tmp->token, arg, i) == 0)
	{
		(*lst) = tmp->next;
		ft_strdel(&(tmp->token));
		free(tmp);
		return ;
	}
	while (tmp != NULL && ft_strncmp(tmp->token, arg, i) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	ft_strdel(&(tmp->token));
	free(tmp);
}

void	push_back(t_tok **lst, char *token)
{
	t_tok		*element;
	t_tok		*tmp;

	element = NULL;
	element = init_element(element);
	element->token = ft_strdup(token);
	if (is_empty(lst))
	{
		(*lst) = element;
		return ;
	}
	tmp = (*lst);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
}

int		modif_list(t_tok **lst, char *arg)
{
	int			i;
	int			len;
	t_tok		*head;

	i = 0;
	len = 0;
	head = (*lst);
	while ((*lst) != NULL)
	{
		i = 0;
		while ((*lst)->token[i])
		{
			if ((*lst)->token[i] == '=')
				len = i;
			i++;
		}
		if (ft_strncmp((*lst)->token, arg, len) == 0)
		{
			(*lst) = head;
			return (1);
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
	return (0);
}
