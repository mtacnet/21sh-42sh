/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:17:36 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:17:38 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ajoute un maillon en debut de liste
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *lst;

	lst = *alst;
	lst->prev = new;
	new->next = lst;
	*alst = new;
}
