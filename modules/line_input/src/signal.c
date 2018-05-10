/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:47:02 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:47:04 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

static void	ctrlchd(int signal)
{
	int		term;
	char	**line;
	t_line	*line_info;

	(void)signal;
	line_info = get_line_info(NULL);
	(line = get_line(NULL)) ? ft_strdel(line) : NULL;
	while (line_info->cursor_y++ < line_info->nb_line)
		ft_putstr(tgoto(tgetstr("do", NULL), 0, 0));
	ft_putendl("");
	if ((*line = (char*)ft_memalloc(sizeof(char) * 1)))
	{
		term = line_info->term;
		ag_putstrs("$>");
		*line_info = init_line_info(0, "$>");
		line_info->term = term;
		line_info->size = 0;
		update_info(line_info, *line);
		is_in_heredoc(3);
	}
	else if (line_info && line_info->size)
	{
		line_info->size = 0;
		sh_error(1, "in function line_input: ctrlchd. Press any key");
	}
}

/*
**	\brief	Gestion de `Ctrl`-`C`
*/

static void	ctrlc(int signal)
{
	int		term;
	char	*prompt;
	char	**line;
	t_line	*line_info;

	(void)signal;
	line_info = get_line_info(NULL);
	(line = get_line(NULL)) ? ft_strdel(line) : NULL;
	while (line_info->cursor_y++ < line_info->nb_line)
		ft_putstr(tgoto(tgetstr("do", NULL), 0, 0));
	ft_putendl("");
	if ((*line = (char*)ft_memalloc(sizeof(char) * (INPUT_BUF_SIZE + 1))))
	{
		term = line_info->term;
		prompt = get_prompt(NULL);
		ag_putstrs(prompt);
		*line_info = init_line_info(INPUT_BUF_SIZE, prompt);
		line_info->term = term;
		update_info(line_info, *line);
	}
	else if (line_info && line_info->size)
	{
		line_info->size = 0;
		sh_error(1, "in function line_input: ctrlc. Press any key to quit");
	}
}

/*
**	\brief	Signaux à ignorer
*/

static void	catch_unused_sig(int signal)
{
	(void)signal;
}

/*
**	\brief	Gestion des signaux
*/

void		launch_signal(void)
{
	signal(SIGTSTP, catch_unused_sig);
	if (!is_in_heredoc(-1))
		signal(SIGINT, ctrlc);
	else
		signal(SIGINT, ctrlchd);
}
