/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:43:05 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:43:12 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_putchar.c
**	\author	Alexis Guérin
**	\date	2 février 2018
**
**	\brief	Affichae d'un caractère sur la sortie standard
*/

#include "libag.h"

/*
**	\brief	Affichage d'un caractère suivi d'un retour à la ligne
**
**	Écrit le caractère `c` suivi d'un retour à la ligne sur la sortie standard.
**
**	\param	c	- caractère
**
**	\return	**nombre de caractères affichés**
*/

int	ag_putcharl(char c)
{
	return (ft_putchar(c) + ft_putchar('\n'));
}

/*
**	\brief	Affichage d'un caractère suivi d'un espace
**
**	Écrit le caractère `c` suivi d'un espace sur la sortie standard.
**
**	\param	c	- caractère
**
**	\return	**nombre de caractères affichés**
*/

int	ag_putchars(char c)
{
	return (ft_putchar(c) + ft_putchar(' '));
}

/*
**	\brief	Affichage d'un caractère _x_ fois.
**
**	\param	c	- caractère à afficher
**	\param	x	- nombre de fois à afficher le caractère
**
**	\return	**nombre de fois** que le caractère a été affiché
**			ou **-1** en cas d'erreur
*/

int	ag_putxchar(char c, int x)
{
	int	i;

	i = -1;
	while (++i < x)
		write(1, &c, 1);
	return (i);
}
