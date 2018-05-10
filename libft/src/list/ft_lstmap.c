/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:18:02 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:18:03 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (!lst)
		*alst = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
		new->prev = lst;
	}
}

/*
** ft_lstmap() applique la fonction f sur chaque maillon de la liste lst et crée
** une liste à partir des retours de cette fonction.
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst1;
	t_list	*new_list;
	t_list	*new_elem;

	lst1 = lst;
	new_list = NULL;
	while (lst1)
	{
		new_elem = f(lst1);
		if (!new_list)
			new_list = new_elem;
		else
			ft_lstaddend(&new_list, new_elem);
		lst1 = lst1->next;
	}
	return (new_list);
}
