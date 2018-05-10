/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:28:42 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:28:44 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "libft.h"
# include "libag.h"
# include "environment.h"
# include "history.h"
# include "libexec.h"
# include "liberror.h"
# include "singletons.h"
# include <sys/types.h>
# include <dirent.h>
# include <limits.h>

/*
**	structs
*/

typedef struct	s_opt
{
	int			n;
	int			e;
}				t_opt;

/*
**	builtin_cd.c
*/

int				builtin_cd(char ***env, char **args, char ***local);

/*
**	builtin_echo.c
*/

int				builtin_echo(char **args);

/*
**	builtin_env.c
*/

int				builtin_env(char **av, char ***env);

/*
**	builtin_exit.c
*/

int				builtin_exit(char **args);
void			exit_final(int exit_val);

/*
**	builtin_history.c
*/

int				builtin_history(char **args, t_lstag **history,\
								const char **env, const char **local);

/*
**	builtin_set.c
*/

int				builtin_set(char **av, char ***loc);

/*
**	builtin_setenv.c
*/

int				builtin_setenv(char **av, char ***env, char ***local);

/*
**	builtin_unsetenv.c
*/

int				builtin_unset(char **av, char ***loc);

/*
**	builtin_unsetenv.c
*/

int				builtin_unsetenv(char **av, char ***env);

/*
**	tools.c
*/

char			*backslash_it(char *root_path, char *path, int c);
char			*clean_path(char *path);
int				return_an_error(char *message);
char			*clear_x_path(char *path, int where, int len);

/*
**	tools2.c
*/

char			*remove_last_dir(char *path, char *new);
char			*concat_args(char **args);
char			what_char_is_it(char *str, int *len);

/*
**	tools3.c
*/

char			*get_path(char *path);
int				from_base_atoi(const char *str, int base);
char			*beacon_pwd(char *str);
void			error_message(char *msg, char *msg2);

#endif
