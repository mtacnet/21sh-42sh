/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:17 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:46:19 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

/*
**	\brief	Affichage des champs de la structure t_line et de ses valeurs
*/

void	debug_struct(t_line line_info, char *msg)
{
	ft_putendl_fd(msg, 2);
	ft_putstr_fd("col : ", 2);
	ft_putnbr_fd(line_info.win_col, 2);
	ft_putstr_fd("\nsize : ", 2);
	ft_putnbr_fd(line_info.size, 2);
	ft_putstr_fd(" len : ", 2);
	ft_putnbr_fd(line_info.len, 2);
	ft_putstr_fd("\ncursor_i : ", 2);
	ft_putnbr_fd(line_info.cursor_i, 2);
	ft_putstr_fd(" cursor_s : ", 2);
	ft_putnbr_fd(line_info.cursor_s, 2);
	ft_putstr_fd(" cursor_x : ", 2);
	ft_putnbr_fd(line_info.cursor_x, 2);
	ft_putstr_fd(" cursor_y : ", 2);
	ft_putnbr_fd(line_info.cursor_y, 2);
	ft_putendl_fd("\n", 2);
}

/*
**	\brief	Affichage du contenu du buffer de `read()`.
*/

void	debug_read(char buf[])
{
	ft_putendl_fd("", 2);
	ft_putnbr_fd(buf[0], 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(buf[1], 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(buf[2], 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(buf[3], 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(buf[4], 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(buf[5], 2);
	ft_putchar_fd(' ', 2);
	ft_putendl_fd("", 2);
}
