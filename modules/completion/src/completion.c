/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:31:38 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:31:40 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
**	Transformation de la liste en tableau à deux dimensions
*/

static char		**list_to_tab(t_list *list)
{
	int		len;
	int		i;
	char	**tab;

	len = ft_lstcount(list);
	if ((tab = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
	{
		i = -1;
		while (++i < len && tab)
		{
			if (!(tab[i] = ft_strdup((char*)list->content)))
			{
				ag_strdeldouble(&tab);
				completion_error();
			}
			list = list->next;
		}
	}
	else
		completion_error();
	return (tab);
}

/*
**	Création d'un nouveau maillon
*/

static t_list	*new_node(const char *path, char *name)
{
	int		dir;
	char	*complete;
	t_list	*node;

	node = NULL;
	if ((complete = ft_strnew(ft_strlen(path) + ft_strlen(name))))
	{
		complete = ft_strcpy(complete, path);
		complete = ft_strcat(complete, name);
		dir = isdir(complete);
		if (!(node = ft_lstnew(name, ft_strlen(name) + 1 + dir)))
			completion_error();
		if (dir)
			node->content = ft_strcat(node->content, "/");
		ft_strdel(&complete);
	}
	else
		completion_error();
	return (node);
}

/*
**	Complétion d'un nom de fichier/dossier
**
**	La fonction cherche les éléments dont le nom commence par le contenu
**	de `word` dans le dossier indiqué par la variable `path`.
*/

static void		complete(const char *word, const char *path, t_list **list)
{
	int				len;
	DIR				*pdir;
	struct dirent	*dir;
	t_list			*node;

	if (!access(path, R_OK) && (pdir = opendir(path)))
	{
		if ((len = ft_strlen(word)) && word[len - 1] == '\\')
			len--;
		while ((dir = readdir(pdir)))
			if ((word[0] && ag_strnequ(word, dir->d_name, len)) ||
				(!word[0] && dir->d_name[0] != '.'))
			{
				node = new_node(path, dir->d_name);
				if (!(*list))
					*list = node;
				else if (!(*list = ft_lstaddalpha(list, node)))
					completion_error();
			}
		closedir(pdir);
	}
}

/*
**	Complétion d'un nom de variable locale/d'environnement
**
**	La fonction cherche les varoables dont le nom commence par le contenu
**	de `word` dans le tableau de variables `env`
*/

static void		complete_env(const char *word, const char *env, t_list **list)
{
	int		len;
	char	*egal;
	t_list	*node;

	egal = ft_strchr(env, '=');
	len = ft_strlen(word);
	if (((!egal || len <= (egal - env))) && ft_strnequ(word, env, len))
	{
		if ((node = ft_lstnew(NULL, 0)))
		{
			if (!(node->content =
				ft_strsub(env, 0, egal ? egal - env : (int)ft_strlen(env))))
			{
				ft_putchar_fd('\n', 2);
				sh_error(1, "in function completion");
			}
			node->content_size = ft_strlen(node->content) + 1;
			if (!(*list))
				*list = node;
			else if (!(*list = ft_lstaddalpha(list, node)))
				completion_error();
		}
		else
			completion_error();
	}
}

/*
**	\brief	Complétion d'une ligne de commande
**
**	La fonction reçoit un mot à compléter et les chemins d'accès où chercher
**	des éléments pouvant le compléter. Si le mot de contient pas de
**	caractère (que son premier caractère est `\0`), la fonction renvoie tous
**	les éléments contenus dans les dossiers indiqués dans le `path`.
**
**	\param	word	- mot à compléter
**	\param	path	- chemin(s) d'accès vers le ou les dossiers où chercher
**					des éléments pour la complétion
**	\param	builtin	- builtins du Shell (peut être `NULL`)
**	\param	var		- variables locales et d'environnement (peut être `NULL`)
**
**	\return	**tableaux de chaînes de caractères** contenant le nom des
**			éléments pouvant compléter le mot
**			ou **NULL** si aucun élément n'a été trouvé) ou en cas d'erreur.
*/

char			**completion(const char *word, const char **path,
							const char **builtin, const char **var)
{
	int		i;
	char	**res;
	t_list	*list;

	res = NULL;
	if (word)
	{
		list = NULL;
		i = -1;
		while (path && path[++i])
			complete(word, path[i], &list);
		i = -1;
		while (builtin && builtin[++i])
			complete_env(word, builtin[i], &list);
		i = -1;
		while (var && var[++i])
			complete_env(word, var[i], &list);
		list ? res = list_to_tab(list) : NULL;
		list ? ft_lstdel(&list, completion_del) : NULL;
	}
	return (res);
}
