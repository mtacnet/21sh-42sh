/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:41:44 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:41:46 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_memrealloc.c
**	\author	Alexis Guérin
**	\date	12 décembre 2018
**
**	\brief	Changement d'une taille d'allocation
*/

#include "libag.h"

/*
**	\brief	Changement d'une taille d'allocation
**
**	La fonction alloue une nouvelle zone de mémoire de taille _newsize_ et copie
**	_old_ dans le nouveau pointeur. La mémoire de _old_ est libérée.
**
**	Si _oldsize_ est plus grand que la taille de _old_, le comportement est
**	indéterminé.
**
**	Voir : ft_memalloc() et ft_memcpy() de la [libft][].
**	[libft]: https://github.com/aguerin42/libft.git
**
**	\param	old		- pointeur sur la zone mémoire à copier
**	\param	oldsize	- taille de l'allocation de l'ancienne zone mémoire
**	\param	newsize - taille de l'allocation pour la nouvelle zone mémoire
**
**	\return	pointeur sur la **nouvelle zone mémoire** allouée
**			où l'ancienne a été copiée, ou **NULL** en cas d'erreur
*/

void	*ag_memrealloc(void *old, size_t oldsize, size_t newsize)
{
	void	*new;

	if ((new = ft_memalloc(newsize)))
		new = ft_memcpy(new, old, oldsize);
	ft_memdel(&old);
	return (new);
}
