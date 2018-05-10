/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:27:43 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:27:44 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**	Fonction de libération de mémoire passée a ag_lstdel()
*/

void	del_l(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
		ft_memdel(&content);
}

/*
**	Parsing basique pour l'attente de ligne
**
**	La fonction renvoie 1 en cas d'erreur dans la ligne
*/

int		verif_parse(char *line)
{
	int	i;

	i = -1;
	if (line)
		while (line[++i])
		{
			if ((line[i + 1] && line[i] == '>' && line[i + 1] == '|') ||
				(line[i + 1] && line[i] == '>' && line[i + 1] == '&') ||
				(line[i + 1] && line[i] == '<' && line[i + 1] == '|') ||
				(line[i + 1] && line[i] == '<' && line[i + 1] == '&'))
				return (1);
		}
	return (0);
}

/*
**	\brief	Regroupement de tableaux
**
**	Regroupe les tableaux de chaînes de caractères
**	(environnement et local) en un seul afin de pouvoir l'envoyer
**	à l'édition de ligne.
**	Si il y a des doublons, les variables de l'environnement sont utilisées
**
**	\param	env		- tableau contenant les variables d'environnement
**	\param	local	- tableau contenant les variables locales
**
**	\return **tableau** regroupant ceux donnés en paramètres
**			ou **NULL** en cas d'erreur
*/

char	**concat_tab(const char **env, const char **local)
{
	int		len;
	int		i;
	int		j;
	char	**t;

	t = NULL;
	if ((len = ag_strlendouble((char**)local)))
	{
		if ((t = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		{
			i = -1;
			j = 0;
			while (t && local && local[++i])
				if (!(t[j++] = ft_strdup(local[i])))
					ag_strdeldouble(&t);
			i = -1;
			while (t && env && env[++i])
				if (ft_setenv((char*)env[i], &t))
					ag_strdeldouble(&t);
		}
		if (!t)
			sh_error_exit(1, "21sh: in function concat_tab");
	}
	return (t);
}
