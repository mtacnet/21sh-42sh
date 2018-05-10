/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:33:11 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:33:12 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static int	add_var(char *new, char ***environment)
{
	int		size;
	int		len;
	char	**copy;

	if (!new || !environment)
		return (1);
	size = 0;
	while (environment[0][size])
		size++;
	if ((copy = dupenv((const char **)*environment, size + 1)))
	{
		ag_strdeldouble(environment);
		if (ft_strchr(new, '='))
			copy[size] = ft_strdup(new);
		else
		{
			len = ft_strlen(new);
			copy[size] = ft_strnew(len + 1);
			ft_strcpy(copy[size], new);
			copy[size][len] = '=';
		}
		*environment = copy;
		return (0);
	}
	return (1);
}

static int	alter_var(char *new, char **environment, int i)
{
	if (new && environment && ft_strchr(new, '='))
	{
		ft_strdel(&environment[i]);
		environment[i] = ft_strdup(new);
		return (0);
	}
	return (1);
}

static int	set(char *new, char ***environment)
{
	int	i;

	if (new && environment)
	{
		if (new[0] == '=')
			return (ft_putendl_fd("setenv: bad assignment", 2));
		if ((i = find_var(new, (const char**)environment[0], 1)) < 0)
			return (add_var(new, environment));
		else
			return (alter_var(new, *environment, i));
	}
	return (1);
}

/*
**	\brief	Création d'une variable d'environnement à partir de deux
**
**	La fonction crée une variable d'environnement de type
**
**		VARIABLE=valeur
**
**	à partir de deux variables séparées, et l'ajoute à l'environnement.
**
**	\param	var			- nom de la variable
**	\param	content		- contenu de la variable
**	\param	environment	- environnement à modifier
**
**	\return	**0** en cas de succès, **1** en cas d'erreur.
*/

int			ft_vcontenv(const char *var, const char *content,
													char ***environment)
{
	char	*varcon;
	int		len;
	int		ret;

	ret = 1;
	if (var && content && environment)
	{
		len = ft_strlen(var) + ft_strlen(content) + 1;
		if (!(varcon = ft_strnew(len)))
			return (ret);
		varcon = ft_strcpy(varcon, var);
		varcon = ft_strcat(varcon, "=");
		varcon = ft_strcat(varcon, content);
		ret = ft_setenv(varcon, environment);
		ft_strdel(&varcon);
	}
	return (ret);
}

/*
**	\brief Ajout ou modification de variable
**
**	Si la variable `new` n'existe pas et qu'elle est correctement formatée,
**	celle-ci est ajoutée. Si elle existe, sa valeur est modifiée.
**
**	\param	new				- variable à ajouter ou modifier
**	\param	environment 	- environment à modifier
**							La variable doit avoir été allouée dynamiquement
**
**	\return	**0** en cas de succès, **1** en cas d'erreur.
*/

int			ft_setenv(char *new, char ***environment)
{
	int	ret;

	ret = 1;
	if (new && environment && *environment)
		ret = set(new, environment);
	return (ret);
}
