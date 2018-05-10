/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libexec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:05 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:06 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBEXEC_H
# define LIBEXEC_H

# include "libft.h"
# include "parser.h"
# include "history.h"
# include "libmt.h"
# include "liberror.h"
# include "environment.h"
# include "builtins.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

/*
**	exec.c
*/

int		ft_expand_dollar(char **cmd, const char **env, const char **local,
							int check_tild);
int		exec(t_exec **exe, char ***env);

/*
** exec_core.c
*/

int		execution(t_exec **exe, int level, char ***env);
int		check_access(char *cmd);

/*
** exec_cmd.c
*/

int		exec_cmd_pipe(t_exec **sub_cmd, t_exec **cmd, char ***env, int here);
int		pre_exec_cmd(char *path, char **args, char **path_tab, char ***env);
int		exec_cmd(t_exec **exe, char ***env);

/*
**	pre_exec.c
*/

int		pre_exec(char *line, char ***env, int ret);

/*
**	split.c
*/

t_exec	*split_logic(t_exec **exe);
t_exec	*split_pipe(t_exec **exe);
t_exec	*split_sep(t_exec **exe);

/*
**	utils.c
*/

int		check_builtins(char *str);
int		is_it_builtin(char **cmd_tab, char ***env, char ***local, int ret);
int		put_here_in_list(t_exec **exe, t_lstag **hd);
int		is_no_redir(t_exec **exe, int what);
void	set_null(t_tok **a, t_exec **b, t_lstag **c);

/*
**	utils2.c
*/

int		open_file2(t_exec *file, t_exec *act);
int		catch_status_ret(pid_t child, int nohang, t_exec **exe, t_exec **sub);
char	**get_cut_path(const char **env);
char	*check_valid_path(char **path_tab, char *cmd);
int		return_free_exec(t_exec **exe);

/*
**	utils3.c
*/

int		count_file(t_exec **exe);
int		get_one_sided_pipe(void);
int		set_here(int f1, int f2, int f3);
void	equal(t_exec **a, t_exec *b, t_exec **c, t_exec *d);
int		return_free_lst(t_tok *token);

/*
**	utils4.c
*/

void	add_add(int *a, int b, int *c, int d);
int		return_t_exec(t_exec **a);
int		check_for_files(t_exec **exe);

/*
**	value_ret.c
*/

void	set_value_ret(int value);

/*
**	get_fd.c
*/

int		get_fd(t_exec **exe, int val);

/*
**	redir.c
*/

t_exec	*remaining_redir(t_exec **exe, int what, int i);
int		process_redir(t_exec **exe);
int		left_here(t_exec **exe, int phd[2]);
int		heredoc(char *line, t_lstag **hd, char **builtin);

#endif
