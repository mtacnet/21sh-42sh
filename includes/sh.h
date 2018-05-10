/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:26:22 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:26:23 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "expansion.h"
# include "libft.h"
# include "libag.h"
# include "libmt.h"
# include "environment.h"
# include "history.h"
# include "line_input.h"
# include "parser.h"
# include "liberror.h"
# include "libexec.h"
# include "heredoc.h"

/*
**	builtin.c
*/

char		**get_shbuiltin(void);

/*
**	environment.c
*/

char		***get_env(char ***env);
char		**create_env(const char **environ);

/*
**	history.c
*/

char		*get_history_file(const char *file);
t_lstag		*init_history(const char **env, const char **loc);

/*
**	line.c
*/

char		*call_line(t_lstag **history, char *hist_file, char **var);

/*
**	local.c
*/

char		***get_loc(char ***loc);
char		**create_loc(const char **env);

/*
**	quotes.c
*/

int			quotes(char **line, char c);

/*
**	signal.c
*/

void		sh_launchsignal(void);
void		sh_resetsignal(void);

/*
**	tools.c
*/

int			verif_parse(char *line);
char		**concat_tab(const char **env, const char **local);

#endif
