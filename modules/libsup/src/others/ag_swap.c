/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:42:24 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:42:26 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_swap.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Échange de pointeur
*/

/*
** \brief	Échange de deux pointeurs sur entiers
**
** \param	a	- premier pointeur
** \param	b	- deuxième pointeur
*/

void	ag_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
