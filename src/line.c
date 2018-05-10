/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:27:15 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:27:16 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "expansion.h"

/*
**	Transformation de la liste en une chaîne de caractères
*/

static char		*list_to_str(t_lstag *list)
{
	int		len;
	char	*str;
	t_lstag	*head;

	head = list;
	len = 0;
	while (list)
	{
		len += list->content_size - 1;
		list = list->next;
	}
	list = head;
	if (!(str = ft_strnew(len)))
		sh_error_exit(1, "in list_to_str function");
	while (str && list)
	{
		str = ft_strcat(str, list->content);
		list = list->next;
	}
	return (str);
}

/*
**	Suppression du backslash en fin de ligne, ou ajout d'un retour à la ligne
**	si l'attente était faite sur une quote
*/

static void		alter_line(char **line, char c)
{
	char	*tmp;

	if (c > 0)
	{
		if (c == '\\')
			line[0][ft_strlen(*line) - 1] = ' ';
		else if (c == '"' || c == '\'' || c == '`')
		{
			tmp = ft_strnew(ft_strlen(*line) + 1);
			tmp = ft_strcpy(tmp, *line);
			tmp = ft_strcat(tmp, "\n");
			ft_strdel(line);
			*line = tmp;
		}
	}
}

static int		read_line2(int *c, char **line, t_lstag **list)
{
	t_lstag		*node;

	alter_line(line, (*c = quotes(line, *c)));
	node = ag_lstnew(*line, ft_strlen(*line) + 1);
	if (list && *list)
		ag_lstaddtail(list, node);
	else
		*list = node;
	if (line && *line && verif_parse(*line))
	{
		ft_strdel(line);
		return (1);
	}
	line && *line ? ft_strdel(line) : NULL;
	return (0);
}

static t_lstag	*read_line(t_lstag *history, char **var)
{
	int		c;
	char	*line;
	t_lstag	*list;

	list = NULL;
	c = 0;
	while (1)
	{
		list ? (void)ft_putchar('\n') : NULL;
		if ((line = line_input(ft_getenv(list ? "PS2" : "PS1",\
							(const char**)var), history, var, get_shbuiltin())))
		{
			if (read_line2(&c, &line, &list))
				break ;
			if (c <= 0 || !list || is_in_heredoc(-1) == 3)
				break ;
			is_in_heredoc(2);
		}
		else
			break ;
	}
	if (is_in_heredoc(-1) == 3 && list)
		ag_lstdel(&list, del_l);
	return (list);
}

/*
**	\brief	Appel de l'édition de ligne
**
**	Appelle l'édition de ligne tant qu'une quote est ouverte,
**	ou qu'un backslash est en fin de ligne
**
**	\return	**commande** ou **NULL** en cas d'erreur
*/

char			*call_line(t_lstag **history, char *hist_file, char **var)
{
	char	*line;
	t_lstag	*list;

	list = read_line(history ? *history : NULL, var);
	is_in_heredoc(0);
	sh_launchsignal();
	line = list_to_str(list);
	list ? ag_lstdel(&list, del_l) : NULL;
	if (!line)
		return (NULL);
	ft_putendl("");
	if (ft_expand_exclam(&line, *history) < 0)
	{
		ft_strdel(&line);
		line = ft_strdup(" ");
		return (line);
	}
	*history = add_history(*history, hist_file, line);
	*history ? *history = ag_lsthead(*history) : NULL;
	return (line);
}
