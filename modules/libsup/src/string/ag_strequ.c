/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:44:00 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:44:03 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_strequ.c
**	\author	Alexis Guérin
**	\date	6 février 2018
**
**	\brief	Comparaison de chaînes de caractères insensible à la casse
*/

#include "libag.h"

/*
**	\brief	Comparaison de chaînes de caractères insensible à la casse
**
**	Comme la fonction `ft_strequ()` de la [libft][], ag_strequ() compare les
**	chaînes `s1` et `s2` pour vérifier qu'elles sont identiques, mais ne
**	fait au contraire pas de différences sur la casse des lettres.
**
**	\param	s1	- première chaîne
**	\param	s2	- deuxième chaîne
**
**	\return	**1** si les chaînes sont identiques ou **0** sinon
*/

int		ag_strequ(char const *s1, char const *s2)
{
	int	size1;
	int	size2;
	int	i;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	i = 0;
	if (size1 != size2)
		return (0);
	while (i < size1)
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
**	\brief	Comparaison de chaînes sur `n` caractères insensible à la casse
**
**	Comme la fonction `ft_strnequ()` de la [libft][], ag_strnequ() compare les
**	chaînes `s1` et `s2` sur `n` pour vérifier qu'elles sont identiques, mais ne
**	fait au contraire pas de différences sur la casse des lettres.
**
**	\param	s1	- première chaîne
**	\param	s2	- deuxième chaîne
**	\param	n	- nombre de caractères à comparer
**
**	\return	**1** si les chaînes sont identiques ou **0** sinon
*/

int		ag_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	while ((s1 && s2) && n > 0)
	{
		if (ft_tolower(*s1) != ft_tolower(*s2))
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (1);
}
