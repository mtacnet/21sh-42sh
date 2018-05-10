/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:52 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:46:54 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

static void	input_simple(char buf[], char **line, t_line *line_info)
{
	int				i;
	char			*l;
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	if (!buf[1] && buf[0] > 31 && buf[0] < 127)
		insert_char(line, buf[0], line_info);
	else if (!buf[1] && buf[0] == 127 && line_info->cursor_i > 0)
		delete_char(line, buf[0], line_info);
	update_info(line_info, *line);
	ft_putstr(tgoto(tgetstr("ch", NULL), 0, 0));
	ft_putstr(tgoto(tgetstr("cd", NULL), 0, 0));
	l = *line;
	if ((int)line_info->len + (int)line_info->prompt >= win.ws_col - 1)
		ag_putstrs(">");
	else
		ag_putstrs((const char*)get_prompt(NULL));
	i = line_info->len - win.ws_col + 4;
	ft_putstr((char const*)&l[i > 0 ? i : 0]);
}

/*
**	\brief	Lecture de l'entrée standard
**
**	La fonction appelle les différentes fonctions de lecture des touches tappées
**	et de gestion de celles-ci, de mise à jour de line_info, de modifications de
**	la ligne de commande et de replacement du curseur.
**
**	\param	line		- ligne de commande
**	\param	line_info	- pointeur sur la structure contenant les informations
**						nécessaires à *line_input*
**	\param	prompt		- chaîne représentant le prompt (peut être `NULL`)
**	\param	history		- historique de commandes (peut être `NULL`)
*/

void		input(char **line, t_line *line_info, char *prompt,
															t_lstag *history)
{
	char	buf[7];

	if (line)
	{
		buf[0] = 0;
		while (buf[0] != 10 && line_info->size)
		{
			update_info(line_info, *line);
			ft_bzero(buf, 7);
			read(0, buf, 6);
			if (line_info->size && line_info->term)
			{
				if (!check_key(line, buf, line_info, history))
				{
					line_info->cursor_s = -1;
					print_line(*line, *line_info, prompt);
					update_info(line_info, *line);
					replace_cursor(*line_info);
				}
			}
			else if (line_info->size)
				input_simple(buf, line, line_info);
		}
	}
}
