/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:33:08 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:33:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

/*
**	\brief	Récupération de variable
**
**	La fonction cherche la variable dans l'environnement
**	et renvoie sa *valeur*.
**
**	Si la variable n'existe pas, *NULL* est renvoyé.
**
**	\param	name		- variable à chercher
**	\param	environment	- environnement où chercher
**
**	\return	**valeur** de la variable ou **NULL** si elle n'existe pas.
*/

char	*ft_getenv(const char *name, const char **environment)
{
	int		i;
	char	*value;

	value = NULL;
	if (name && environment)
	{
		if ((i = find_var(name, environment, 0)) >= 0)
		{
			value = (char*)environment[i];
			if ((value = ft_strchr(value, '=')))
				value++;
		}
	}
	return (value);
}

/*
**	\brief	Recherche de variable
**
**	La fonction cherche la variable `var` dans l'environnement et renvoie
**	l'*indice de sa position*.
**	Le booléen `egal` permet d'indiquer si la recherche doit ignorer le
**	caractère égal et ce qui suit lors de la comparaison (`1`) ou non (`0`).
**
**	\param	var			- variable à chercher
**	\param	environment	- environnement où chercher
**	\param	egal		- booléen : **0** si toute la chaîne `var` doit être
**						comparée, **1** si seuls les caractères précédents
**						le `=` doivent être comparés
**
**	\return	**indice** de la variable dans `environment`
**			ou **-1** si elle n'y est pas.
*/

int		find_var(const char *var, const char **environment, int egal)
{
	int		i;
	int		len;
	char	*ret;

	if (var && environment)
	{
		i = -1;
		if (egal)
		{
			ret = ft_strchr(var, '=');
			if (ret)
				len = (ret - var);
			else
				len = ft_strlen(var);
		}
		else
			len = ft_strlen(var);
		while (environment[++i])
			if (ft_strnequ(var, (char*)environment[i], len))
				if ((environment[i][len] && environment[i][len] == '='))
					return (i);
	}
	return (-1);
}
