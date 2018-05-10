/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:37:13 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:37:16 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	history.h
**	\author	Alexis Guérin
**	\date	29 janvier 2018
*/

#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"
# include "libag.h"
# include "liberror.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <unistd.h>

int		not_empty(char *line);
t_lstag	*add_history_lst(t_lstag *history, char *line);
t_lstag	*add_history(t_lstag *history, char *path, char *line);
int		cut_history(t_lstag *history, char *path);
void	delete_history_file_content(char *path);
void	delete_history_list(t_lstag **history);
int		open_history(char *path);
void	print_history(t_lstag *history, int nb);
t_lstag	*read_history(char *path, t_lstag *history);
t_lstag	*search_history_begin(t_lstag *history, char *command);
char	*search_history_content(t_lstag *history, const char *pattern);
void	write_history(char *path, t_lstag *history);
t_lstag	**get_history(t_lstag **history);

#endif
