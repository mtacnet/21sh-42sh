/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:39:21 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:39:25 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_atoi_base.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Conversion d'une chaîne en entier
*/

#include "libag.h"

static int	error_verification(const char *str, int base)
{
	if (base < 2 || base > 37)
	{
		ft_putendl("Erreur : base incorrecte - ft_atoi_base");
		return (-1);
	}
	if (!str)
	{
		ft_putendl("Erreur : chaîne (null) - ft_atoi_base");
		return (-1);
	}
	return (0);
}

static int	conv_dec(const char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'Z')
		return (c - 55);
	if (c >= 'a' && c <= 'z')
		return (c - 87);
	ft_putendl("Erreur : problème de formatage de la chaîne - ft_atoi_base");
	return (-1);
}

/*
**	\brief
**
**	Comme la fonction ft_atoi, ag_atoi_base renvoie un entier converti (en base
**	10) depuis une chaîne, mais représenté dans n'importe quelle base
**	(1 < base < 38).
**	ft_atoi_base ne vérifie pas si la chaîne envoyée est correctement formatée
**	en fonction de la base dans laquelle elle est représentée.
**
**	\param	str		- chaîne représentant le nombre
**	\param	base	- base dans laquelle est représenté le nombre
**
**	\return	**entier** représentant le nombre en base 10
*/

int			ag_atoi_base(const char *str, int base)
{
	int	i;
	int	nb;
	int	power;

	if (error_verification(str, base))
		return (-1);
	i = 0;
	nb = 0;
	if (base == 10)
		return (ft_atoi(str));
	power = ft_strlen(&str[i]) - 1;
	while (str[i] != '\0')
		nb += (conv_dec(str[i++]) * ag_pow(base, power--));
	return (nb);
}
