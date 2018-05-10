/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:55 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:57 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	view_llist(t_tok **lst)
{
	t_tok		*head;

	head = (*lst);
	while ((*lst) != NULL)
	{
		ft_putstr("token_id: ");
		ft_putnbr((*lst)->token_id);
		ft_putchar('\n');
		ft_putstr((*lst)->token);
		if ((*lst)->next != NULL)
			ft_putstr(" ");
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
}

void	view_list(t_tok **lst)
{
	t_tok		*head;

	head = (*lst);
	while ((*lst) != NULL)
	{
		ft_putstr("id: ");
		ft_putnbr((*lst)->id);
		ft_putchar('\n');
		ft_putstr("id_token: ");
		ft_putnbr((*lst)->token_id);
		ft_putchar('\n');
		ft_putstr("token: ");
		ft_putendl((*lst)->token);
		if ((*lst)->next != NULL)
			ft_putchar('\n');
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
}
