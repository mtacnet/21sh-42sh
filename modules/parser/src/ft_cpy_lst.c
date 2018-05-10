/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:44 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:45 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	cpy_lst(t_tok **lst_dest, t_tok **lst_src)
{
	t_tok		*head;

	head = (*lst_src);
	while ((*lst_src) != NULL)
	{
		push_elemx(lst_dest, (*lst_src)->token, (*lst_src)->token_id,
				(*lst_src)->id);
		(*lst_src) = (*lst_src)->next;
	}
	(*lst_src) = head;
}
