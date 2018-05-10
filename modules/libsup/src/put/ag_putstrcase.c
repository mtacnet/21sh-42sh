/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_putstrcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:43:34 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:43:36 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_putstrcase.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Affichage d'une chaîne dans une seule casse
*/

#include "libag.h"

/*
**	\brief	Affichage d'une chaîne en minuscule
**
**	\param	str	- chaîne de caractères
**
**	\return **nombre de caractères** affichés
*/

int	ag_putstrlower(const char *str)
{
	int	i;
	int	cmp;

	if (!str)
		return (-1);
	i = 0;
	cmp = 0;
	while (str[i])
		cmp += ft_putchar(ft_tolower(str[i++]));
	return (cmp);
}

/*
**	\brief	Affichage d'une chaîne en majuscule
**
**	\param	str	- chaîne de caractères
**
**	\return **nombre de caractères** affichés
*/

int	ag_putstrupper(const char *str)
{
	int	i;
	int	cmp;

	if (!str)
		return (-1);
	i = 0;
	cmp = 0;
	while (str[i])
		cmp += ft_putchar(ft_toupper(str[i++]));
	return (cmp);
}
