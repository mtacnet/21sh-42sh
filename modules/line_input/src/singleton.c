/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:47:05 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:47:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

/*
**	\brief	Pointeur sur la structure `t_line`
**
**	Pour initialiser le sigleton, l'appel devra s'effectuer en donnant le
**	pointeur de la structure en paramètre de la fonction.
**	Pour simplement récupérer le pointeur sur la stucture, le paramètre `info`
**	devra être `NULL`
*/

t_line	*get_line_info(t_line *info)
{
	static t_line	*line_info = NULL;

	if (info)
		line_info = info;
	return (line_info);
}

/*
**	\brief	Pointeur sur le tableau d'environnement
**
**	Pour inialiser le sigleton, l'apple devra s'effectuer en donnant le
**	tableau de chaîne de caractère contenant les variables d'environnement.
**	Pour simplement récupéer la variable, le paramètre `env` devra être
**	`NULL`.
*/

char	**get_environ(char **env)
{
	static char **save_env = NULL;

	if (env)
		save_env = env;
	return (save_env);
}

/*
**	\brief	Pointeur sur le tableau de builtin
**
**	Pour inialiser le sigleton, l'apple devra s'effectuer en donnant le
**	tableau de chaîne de caractère contenant les variables d'environnement.
**	Pour simplement récupéer la variable, le paramètre `builtin` devra être
**	`NULL`.
*/

char	**get_builtin(char **builtin)
{
	static char **save_builtin = NULL;

	if (builtin)
		save_builtin = builtin;
	return (save_builtin);
}

/*
**	\brief	Pointeur sur la chaîne de caractères de la ligne
**
**	Pour initialiser le sigleton, l'appel devra s'effectuer en donnant le
**	pointeur de la chaîne de caractères en paramètre de la fonction.
**	Pour simplement récupérer le pointeur sur la chaîne, le paramètre `line`
**	devra être `NULL`
*/

char	**get_line(char **line)
{
	static char	**save_line = NULL;

	if (line)
		save_line = line;
	return (save_line);
}

/*
**	\brief	Chaîne de caractères pour le prompt
**
**	Pour initialiser le sigleton, l'appel devra s'effectuer en donnant la
**	chaîne de caractères en paramètre de la fonction.
**	Pour simplement récupérer la chaîne, le paramètre `prompt` devra être `NULL`
*/

char	*get_prompt(char *prompt)
{
	static char	*save_prompt = NULL;

	if (prompt)
		save_prompt = prompt;
	return (save_prompt);
}
