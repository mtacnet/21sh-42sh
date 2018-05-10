/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:17 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:18 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libexec.h"

static void		part_one_pipe(int p[2], t_exec **sub_cmd, int phd[2],\
	char ***env)
{
	set_here(p[0], p[1], 1);
	if (!is_no_redir(sub_cmd, 0))
		set_here(phd[1], phd[0], 0);
	exit(execution(sub_cmd, 1, env));
}

int				exec_cmd_pipe(t_exec **sub_cmd, t_exec **cmd, char ***env,\
	int no_pipe)
{
	pid_t	child;
	int		p[2];
	int		phd[2];

	if (pipe(p) == -1)
		return (sh_error_int(18, "pipe"));
	if (!is_no_redir(sub_cmd, 0) && pipe(phd) == -1)
		return (sh_error_int(18, "pipe"));
	if ((child = fork()) == -1)
		return (sh_error_int(11, "fork"));
	if (!child)
		part_one_pipe(p, sub_cmd, phd, env);
	else
	{
		if (!no_pipe)
			set_here(p[1], p[0], 0);
		if (!is_no_redir(sub_cmd, 0))
			if (left_here(sub_cmd, phd) == -1)
				return (-1);
		catch_status_ret(child, 1, sub_cmd, cmd);
		exec_cmd(cmd, env);
	}
	return (0);
}

static void		choose_what_to_return(char *name)
{
	if (name)
	{
		if (access(name, F_OK))
			sh_error(10, name);
		else
			sh_error(12, name);
	}
}

int				pre_exec_cmd(char *path, char **args, char **path_tab,
						char ***env)
{
	int		ret;

	ret = 0;
	if (path || (!path && !access(args[0], F_OK | X_OK)))
	{
		if (path && (ret = check_access(path)))
			exit(ret);
		else if (!path && (ret = check_access(args[0])))
			exit(ret);
		if (path)
			execve(path, args, *env);
		else
			execve(args[0], args, *env);
		exit(0);
	}
	else
	{
		path_tab ? free_tab(path_tab) : NULL;
		choose_what_to_return(args ? args[0] : NULL);
		args ? free(args) : NULL;
		exit(127);
	}
	exit(ret);
}

int				exec_cmd(t_exec **exe, char ***env)
{
	char	*final_path;
	char	**path_tab;
	int		ret;
	char	**args;
	char	***local;

	if (!(args = list_to_tab(&(*exe)->token)))
		return (sh_error_int(1, "in list_to_tab function"));
	if (process_redir(exe))
		return (-1);
	local = get_loc(NULL);
	final_path = NULL;
	path_tab = get_cut_path((const char **)*env);
	if ((*exe)->token->token_id != OP_CMD)
		return (0);
	if ((ret = is_it_builtin(args, env, local, -1)) == -1)
	{
		if (!ft_strchr(args[0], '/'))
			final_path = check_valid_path(path_tab, args[0]);
		ret = pre_exec_cmd(final_path, args, path_tab, env);
	}
	else
		free(args);
	path_tab ? free_tab(path_tab) : NULL;
	return (ret);
}
