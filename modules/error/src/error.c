/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:33:54 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:33:55 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liberror.h"

static void		msg_error2(int val, char *fct)
{
	if (val == 14)
		ft_putstr_fd("ERROR: OLDPWD not set: ", 2);
	else if (val == 15)
		ft_putstr_fd("ERROR: HOME not set: ", 2);
	else if (val == 16)
		ft_putstr_fd("ERROR: not a directory: ", 2);
	else if (val == 17)
		ft_putstr_fd("ERROR: too many arguments: ", 2);
	else if (val == 18)
		ft_putstr_fd("ERROR: function failed: ", 2);
	else if (val == 19)
		ft_putstr_fd("ERROR: syntax error near unexpected token: ", 2);
	else if (val == 20)
		ft_putstr_fd("ERROR: syntax error near unexpected token `newline'", 2);
	else if (val == 21)
		ft_putstr_fd("ERROR: ambiguous redirect: ", 2);
	else if (val == 22)
		ft_putstr_fd("ERROR: Bad file descriptor: ", 2);
	if (fct != NULL)
		ft_putendl_fd(fct, 2);
	else
		ft_putendl_fd("", 2);
}

static void		msg_error(int val, char *fct)
{
	if (val == 1)
		ft_putstr_fd("ERROR: memory allocation: ", 2);
	else if (val == 4)
		ft_putstr_fd("ERROR: directory creation: ", 2);
	else if (val == 5)
		ft_putstr_fd("ERROR: file creation: ", 2);
	else if (val == 6)
		ft_putstr_fd("ERROR: directory opening: ", 2);
	else if (val == 7)
		ft_putstr_fd("ERROR: file opening: ", 2);
	else if (val == 8)
		ft_putstr_fd("ERROR: no such file or directory: ", 2);
	else if (val == 9)
		ft_putstr_fd("ERROR: variable not set: ", 2);
	else if (val == 10)
		ft_putstr_fd("ERROR: command not found: ", 2);
	else if (val == 11)
		ft_putstr_fd("ERROR: child processus creation impossible: ", 2);
	else if (val == 12)
		ft_putstr_fd("ERROR: permission denied ", 2);
	else if (val == 13)
		ft_putstr_fd("ERROR: Runtime problem: ", 2);
	msg_error2(val, fct);
}

void			*sh_error(int val, char *fct)
{
	msg_error(val, fct);
	return (NULL);
}

int				sh_error_int(int val, char *fct)
{
	msg_error(val, fct);
	return (-1);
}

void			*sh_error_exit(int val, char *fct)
{
	msg_error(val, fct);
	ft_putendl_fd("EXIT_SHELL: Bye Bye !", 2);
	exit(EXIT_FAILURE);
}
