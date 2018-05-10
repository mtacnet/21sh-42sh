/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:44:10 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:44:11 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_strnrchr.c
**	\author	Alexis Guérin
**	\date	16 février 2018
*/

#include "libag.h"

/*
**	\brief	Recherche d'un caractère dans une chaîne
**
**	ag_strnrchr() renvoie le pointeur de la dernière occurence du caractère `c`
** 	trouvé dans la chaîne `s`.
**	La recherche s'effectue sur `n` caractères au maximun.
** 	Si c n'est pas trouvé dans `s`, NULL est renvoyé.
**
**	\param	s	- chaîne de caractères
**	\param	c	- caractère à rechercher
**	\param	n	- nombre de caractères maximum à comparer
**
**	\return **pointeur** sur le caractère trouvé ou
**			**NULL** si celui-ci n'est pas présent
*/

char	*ag_strnrchr(const char *s, int c, int n)
{
	char *s1;

	s1 = NULL;
	while (*s && n > 0)
	{
		if (*s == c)
			s1 = (char*)s;
		s++;
		n--;
	}
	if (*s == c)
		return ((char*)s);
	else if (s1)
		return (s1);
	return (NULL);
}
