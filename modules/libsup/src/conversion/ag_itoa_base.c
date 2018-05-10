/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:39:26 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:39:29 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_itoa_base.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Conversion d'un entier en une chaîne de caractères
*/

#include "libag.h"

static char	*ag_zero(char *nbr)
{
	nbr = (char*)ft_memalloc(sizeof(char) * 2);
	ft_strcpy(nbr, "0");
	return (nbr);
}

static int	ag_size_itoa(unsigned long nb, int base)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb /= base;
	}
	return (i);
}

/*
**	\brief	Conversion d'un entier en une chaîne de caractères
**
**	Conversion d'un nombre représenté en base 10, vers une chaîne de
**	caractères dans n'importe quelle base (1 > base > 38).
**
**	\param	nb		- nombre
**	\param	base	- base dans laquelle représenter le nombre à sa sortie
**
**	\return	**nombre** en base `base` ou **NULL** en cas d'erreur
*/

char		*ag_itoa_base(unsigned long nb, int base)
{
	long	mod;
	size_t	size;
	char	*nbr;

	if (base < 2 || base > 37)
	{
		ft_putendl("Base incorrect...");
		return (NULL);
	}
	nbr = NULL;
	if (nb == 0)
		return (ag_zero(nbr));
	size = ag_size_itoa(nb, base);
	if ((nbr = (char*)ft_memalloc(size + 1)))
	{
		nbr[size--] = '\0';
		while (nb > 0)
		{
			mod = nb % base;
			nbr[size--] = (mod > 9 ? mod - 10 + 'a' : mod + '0');
			nb /= base;
		}
		return (nbr);
	}
	return (NULL);
}
