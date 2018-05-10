/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:26:38 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:26:41 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**	Cette fonction ajoute 1 au SHLVL ou le met a un dans les cas speciaux.
*/

static char		*shlvl_inc(char *str)
{
	char		*shlvl;

	shlvl = NULL;
	if (str)
	{
		if (!ft_isdigit(str[0]))
			return (ft_strdup("1"));
		else
		{
			shlvl = ft_itoa(ft_atoi(str));
			if (shlvl && ft_strcmp(shlvl, str))
			{
				ft_strdel(&shlvl);
				return (ft_strdup("1"));
			}
			ft_strdel(&shlvl);
			if (ft_atoi(str) == 2147483647)
				return (ft_strdup("1"));
			shlvl = ft_itoa(ft_atoi(str) + 1);
		}
	}
	return (shlvl);
}

/*
**	\brief	Obtention de l'environnement
**
**	_Sigleton_ permettant d'obtenir et de mettre à jour le pointeur sur les
**	variables d'environnement.
**	La fonction doit être appelée une première fois avec `env` non nul afin
**	d'initialiser le sigleton. Les appels suivants peuvent être effectués avec
**	`env` nul pour seulement obtenir le pointeur,
**	ou non nul pour le mettre à jour
**
**	\param	env	- pointeur sur la tête de liste
**
**	\return	pointeur sur l'**environnement** ou **NULL**
**			si celui-ci n'existe pas ou que le pointeur n'a pas été initialisé
*/

char			***get_env(char ***env)
{
	static char	***e = NULL;

	if (env)
		e = env;
	return (e);
}

/*
**	\brief	Création des variables d'environnement
**
**	La fonction créée le tableau des variables d'environnement,
**	elle y copie l'environnement actuel si celui-ci existe ou en initialise
**	un nouveau sinon, contenant :
**	- PWD : répertoire actuel,
**	- SHLVL : niveau du Shell,
**	Cette fonction met aussi a jour le shlvl de l'env en entree.
**
**	\param	environ	- environnement à copier
**
**	\return	**variables d'environnement** ou **NULL** en cas d'erreur
*/

char			**create_env(const char **environ)
{
	char		**env;
	char		*shlvl;
	char		*tmp;

	shlvl = NULL;
	if ((!environ || !environ[0]) && ((env = (char**)ft_memalloc(sizeof(char*)\
						* (2 + 1)))))
	{
		if (!(env[0] = ft_strdup("SHLVL=0")))
			ag_strdeldouble(&env);
	}
	else
		env = dupenv((const char**)environ, ag_strlendouble((char **)environ));
	if (!env)
		sh_error_exit(1, "in create_env function");
	if ((shlvl = ft_getenv("SHLVL", (const char **)env)))
		ft_vcontenv("SHLVL", (shlvl = shlvl_inc(shlvl)), &env);
	else
		ft_vcontenv("SHLVL", "1", &env);
	ft_vcontenv("PWD", (tmp = getcwd(NULL, 0)), &env);
	beacon_pwd(tmp);
	shlvl ? ft_strdel(&shlvl) : NULL;
	tmp ? ft_strdel(&tmp) : NULL;
	return (env);
}
