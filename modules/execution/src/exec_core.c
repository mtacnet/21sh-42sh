/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:24 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:25 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libexec.h"

int					check_access(char *cmd)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (0);
		else
		{
			ft_putendl_fd("ERROR: Permission Denied", 2);
			exit(126);
		}
	}
	else
		return (1);
	return (-1);
}

static int			call_first_pipe(t_exec **exe, char ***env, t_exec *p)
{
	int			ret;
	pid_t		child;
	int			phd[2];

	ret = 0;
	if (!is_no_redir(&p, 0) && pipe(phd) == -1)
		return (sh_error_int(18, "pipe"));
	if ((child = fork()) == -1)
		return (sh_error_int(11, "fork"));
	if (!child)
	{
		if (!is_no_redir(&p, 0))
			set_here(phd[1], phd[0], 0);
		exit(exec_cmd_pipe(exe, &p, env, !is_no_redir(&p, 0)));
	}
	else
	{
		if (left_here(&p, phd) == -1)
			return (return_t_exec(&p));
		ret = catch_status_ret(child, 0, exe, NULL);
		freelst_exec(&p);
	}
	return (ret);
}

static int			call_simple_cmd(t_exec **exe, char ***env, int level)
{
	int				ret;
	pid_t			child;
	int				phd[2];
	int				tmp;

	tmp = dup(0);
	ret = 0;
	if (!is_no_redir(exe, 0) && pipe(phd) == -1)
		return (sh_error_int(18, "pipe"));
	if ((child = fork()) == -1)
		return (sh_error_int(11, "fork"));
	if (!child)
	{
		if (!is_no_redir(exe, 0))
			set_here(phd[1], phd[0], 0);
		exit(exec_cmd(exe, env));
	}
	else
	{
		if (left_here(exe, phd) == -1)
			kill(child, SIGSTOP);
		ret = catch_status_ret(child, level, exe, NULL);
	}
	dup2(tmp, 0);
	return (ret);
}

static int			exec_dup(t_exec **exe, char ***env)
{
	int		ret;
	int		lol;

	ret = 0;
	lol = 0;
	lol = dup(1);
	ret = exec_cmd(exe, env);
	dup2(lol, 1);
	close(lol);
	return (ret);
}

/*
** La fonction appelle les commandes en fonction des opérateurs logique
*/

int					execution(t_exec **exe, int level, char ***env)
{
	t_exec		*p;
	int			ret;

	ret = 0;
	if (exe)
	{
		if ((p = split_pipe(exe)))
		{
			if (level++)
				ret = exec_cmd_pipe(exe, &p, env, !is_no_redir(&p, 0));
			else if ((ret = call_first_pipe(exe, env, p)) == -1)
				return (-1);
		}
		else
		{
			if (level || check_builtins((*exe)->token->token))
				ret = exec_dup(exe, env);
			else if ((ret = call_simple_cmd(exe, env, level)) == -1)
				return (-1);
		}
	}
	return (ret);
}
