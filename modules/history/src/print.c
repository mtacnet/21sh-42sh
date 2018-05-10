/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:38:06 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:38:10 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	print.c
**	\author	Alexis Guérin
**	\date	31 janvier 2018
**
**	\brief	Affichage du contenu de l'historique
*/

#include "history.h"

static void		print(t_lstag *history, int nb, int len)
{
	int	i;

	i = len;
	while (history && i--)
	{
		ag_putxchar(' ', 5 - ag_nbrlen(len - --nb));
		ag_putnbrs(len - nb);
		ft_putendl(history->content);
		history = history->prev;
	}
}

static t_lstag	*find_node(t_lstag *history, int nb)
{
	while (--nb && history)
		history = history->next;
	return (history);
}

/*
**	\brief	Affichage du contenu de l'historique
**
**	La fonction affiche les préédentes commandes, précédées d'un numéro de
**	ligne.
**
**	\param	history	- historique
**	\param	nb		- nombre de ligne à afficher. Si `nb` est négatif, toutes
**					les lignes sont affichées.
*/

void			print_history(t_lstag *history, int nb)
{
	int				len;

	if (history)
	{
		len = ag_lstcountelem(history);
		if (nb >= 0 && nb < len)
			history = find_node(history, nb);
		else
		{
			history = ag_lsttail(history);
			nb = len;
		}
		print(history, nb, len);
	}
}
