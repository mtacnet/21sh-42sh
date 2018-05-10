/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_strdeldouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:41:50 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:41:52 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_strdeldouble.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Suppression d'un tableau de chaîne de caractères
*/

#include "libag.h"

/*
**	\brief	Suppression d'un tableau de chaîne de caractères
**
**	Libère la mémoire la mémoire allouée pour le double pointeur sur `char`.
**	Le pointeur est mis à `NULL`.
**	La première dimension du tableau doit être délimitée par `\0`.
**
**	\param	str	- pointeur sur un tableau de chaîne
*/

void	ag_strdeldouble(char ***str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[0][i])
			ft_strdel(&str[0][i++]);
		ft_memdel((void**)str);
	}
}
