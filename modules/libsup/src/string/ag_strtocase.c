/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_strtocase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:44:13 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:44:14 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_strtocase.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Changement de la casse d'une chaîne de caractères
*/

#include "libag.h"

/*
**	\brief	Passage d'une chaîne de caractères en minuscule
**
**	Transforme les caractères majuscules d'une chaîne de caractères
**	en minuscules.
**	La chaîne doit avoir été allouée dynamiquement.
**
**	\param	str	- chaîne de caractères
**
**	\return	**la chaîne** modifiée
*/

char	*ag_strtolower(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}

/*
**	\brief	Passage d'une chaîne de caractères en majucule
**
**	Transforme les caractères minuscules d'une chaîne de caractères
**	en majuscules.
**	La chaîne doit avoir été allouée dynamiquement.
**
**	\param	str	- chaîne de caractères
**
**	\return	**la chaîne** modifiée
*/

char	*ag_strtoupper(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}
