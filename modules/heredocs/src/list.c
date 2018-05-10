/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:35:55 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:36:11 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int		istok(char c)
{
	if (c == '|' || c == '&' || c == '>' || c == '<' || c == '=' || c == ';')
		return (1);
	return (0);
}

/*
**	Fonction de libération de mémoire donnée à ag_lstdel()
*/

void	del_h(void *content, size_t content_size)
{
	if (content_size)
		NULL;
	if (content)
		ft_memdel(&content);
}

/*
**	Transformation de liste en une chaîne de caractères
*/

char	*lst_to_str(t_lstag *list)
{
	int		len;
	char	*str;
	t_lstag	*head;

	head = list;
	len = 0;
	while (list)
	{
		len += list->content_size;
		list = list->next;
	}
	list = head;
	if (!(str = ft_strnew(len)))
		sh_error_exit(1, "in list_to_str function");
	while (str && list)
	{
		str = ft_strcat(str, list->content);
		str = ft_strcat(str, "\n");
		list = list->next;
	}
	return (str);
}
