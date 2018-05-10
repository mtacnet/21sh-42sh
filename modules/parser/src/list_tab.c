/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:49:01 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:49:02 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**list_to_tab(t_tok **lst)
{
	int			i;
	size_t		j;
	char		**array;
	t_tok		*head;

	i = 0;
	j = 0;
	array = NULL;
	head = (*lst);
	while ((*lst) != NULL)
	{
		j++;
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
	if (!(array = ft_memalloc(sizeof(*array) * (j + 1))))
		sh_error_exit(1, "function list_to_tab");
	while ((*lst) != NULL)
	{
		array[i] = (*lst)->token;
		(*lst) = (*lst)->next;
		i++;
	}
	(*lst) = head;
	return (array);
}

void	tab_to_list(t_tok **lst, char **array)
{
	int		i;

	i = 0;
	while (array[i] && array[i][0] != '\0')
	{
		push_elem(lst, array[i]);
		i++;
	}
}
