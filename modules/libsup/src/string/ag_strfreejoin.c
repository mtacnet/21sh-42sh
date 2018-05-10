/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:44:03 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:44:06 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_strfreejoin.c
**	\author	Alexis Guérin
**	\date	5 février 2018
**
**	\brief	Concaténation de chaînes
*/

#include "libag.h"

/*
**	\brief	Concaténation chaînes avec libération de mémoire
**
**	`ag_strfreejoin` est identique `ft_strjoin`, mais libère la mémoire de `s1`.
**
**	\param	s1	- première chaîne, dont la mémoire sera libérée
**	\param	s2	- deuxième chaîne
**
**	\return	**chaîne** résultant de la concaténation de `s1` et `s2`
**			ou **NULL** en cas d'erreur
*/

char			*ag_strfreejoin(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = (s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0);
	if ((str = ft_strnew(len)))
	{
		len = 0;
		while (s1 && s1[len])
		{
			str[len] = s1[len];
			len++;
		}
		while (*s2)
		{
			str[len++] = *s2;
			s2++;
		}
		str[len] = '\0';
		if (s1)
			ft_strdel(&s1);
		return (str);
	}
	return (NULL);
}
