/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:55 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:46:57 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

static void	change_word(int i, char m, char *line, t_line *line_info)
{
	if (m == 67)
	{
		while (line[i + 1] && !ft_isalnum(line[i + 1]))
			++i;
		while (line[i + 1] && ft_isalnum(line[i + 1]))
			++i;
	}
	else if (m == 68)
	{
		if (i > 0 && ft_isalnum(line[i]) && !ft_isalnum(line[i - 1]))
			--i;
		while (i > 0 && !ft_isalnum(line[i]))
			--i;
		while (i > 0 && ft_isalnum(line[i - 1]))
			--i;
	}
	line_info->cursor_i = i;
}

static void	change_position(int i, char n, char m, t_line *line_info)
{
	if (m == 68 && i > 0)
		--i;
	else if (m == 67 && i < (int)line_info->len - 1)
		++i;
	else if (m == 72)
		i = 0;
	else if (m == 70)
		i = (line_info->len - 1);
	else if (n == 54 && m == 65)
		i = (i >= (int)line_info->win_col) ? i - line_info->win_col : 0;
	else if (n == 54 && m == 66 && i < (int)line_info->len)
		i = (i + (int)line_info->win_col <= (int)line_info->len) ?
								i + line_info->win_col : line_info->len - 1;
	line_info->cursor_i = i;
}

static int	selection2(int i, t_line *line_info)
{
	if (((i-- + line_info->prompt) % line_info->win_col))
		ft_putstr(tgoto(tgetstr("le", NULL), 0, 0));
	else
	{
		ft_putstr(tgoto(tgetstr("up", NULL), 0, 0));
		ft_putstr(tgoto(tgetstr("ch", NULL), 0,
		line_info->win_col - 1));
		line_info->cursor_y--;
	}
	return (i);
}

/*
**	\brief	Sélection de caractère sur la ligne de commande
*/

int			selection(char n, char m, char *line, t_line *line_info)
{
	int	i;

	if (line && line_info &&
		(m == 65 || m == 66 || m == 67 || m == 68 || m == 70 || m == 72))
	{
		i = line_info->cursor_i;
		if (n == 50 || m == 72 || m == 70 || m == 65 || m == 66)
			change_position(i, n, m, line_info);
		else if (n == 54)
			change_word(i, m, line, line_info);
		if (i == (int)line_info->len && i > 0 && m == 68)
			selection2(i, line_info);
		if (line_info->cursor_s == -1 && i != (int)line_info->cursor_i)
			line_info->cursor_s = i;
		if (line_info->cursor_s >= 0)
		{
			print_line(line, *line_info, get_prompt(NULL));
			update_info(line_info, (const char*)line);
			replace_cursor(*line_info);
		}
	}
	return (1);
}
