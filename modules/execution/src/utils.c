/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:42 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:43 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexec.h"

int		check_builtins(char *str)
{
	if (ft_strequ("env", str))
		return (1);
	else if (ft_strequ("echo", str))
		return (2);
	else if (ft_strequ("set", str))
		return (3);
	else if (ft_strequ("history", str))
		return (4);
	else if (ft_strequ("setenv", str))
		return (5);
	else if (ft_strequ("unsetenv", str))
		return (6);
	else if (ft_strequ("unset", str))
		return (7);
	else if (ft_strequ("cd", str))
		return (8);
	else if (ft_strequ("exit", str))
		return (9);
	else
		return (0);
}

int		is_it_builtin(char **cmd_tab, char ***env, char ***local, int ret)
{
	if (ft_strequ(cmd_tab[0], "echo"))
		ret = builtin_echo(&cmd_tab[1]) == -1 ? 1 : 0;
	else if (ft_strequ(cmd_tab[0], "cd"))
		ret = builtin_cd(env, &cmd_tab[1], local) == -1 ? 1 : 0;
	else if (ft_strequ(cmd_tab[0], "setenv"))
		ret = builtin_setenv(&cmd_tab[1], env, local);
	else if (ft_strequ(cmd_tab[0], "unsetenv"))
		ret = builtin_unsetenv(&cmd_tab[1], env) == -1 ? 1 : 0;
	else if (ft_strequ(cmd_tab[0], "set"))
		ret = builtin_set(&cmd_tab[1], local) == -1 ? 1 : 0;
	else if (ft_strequ(cmd_tab[0], "unset"))
		ret = builtin_unset(&cmd_tab[1], local) == -1 ? 1 : 0;
	else if (ft_strequ(cmd_tab[0], "history"))
	{
		ret = builtin_history(&cmd_tab[1], get_history(NULL),
				(const char**)*env, (const char**)*local) == -1 ? 1 : 0;
	}
	else if (ft_strequ(cmd_tab[0], "exit"))
		ret = builtin_exit(&cmd_tab[1]) == -1 ? 1 : 0;
	if (ft_strequ(cmd_tab[0], "env"))
		ret = builtin_env(&cmd_tab[1], env) == -1 ? 1 : 0;
	else
		ret ? set_value_ret(2) : set_value_ret(0);
	return (ret);
}

int		put_here_in_list(t_exec **exe, t_lstag **hd)
{
	t_exec		*tmp;
	t_lstag		*tmp2;

	if (!exe || !hd)
		return (-1);
	tmp = *exe;
	tmp2 = *hd;
	while (tmp)
	{
		if (tmp->token && tmp->token->token_id == OP_HEREDOC)
		{
			if (tmp->next && tmp->next->token)
			{
				ft_strdel(&tmp->next->token->token);
				if (!(tmp->next->token->token = ft_strdup(tmp2->content)))
					return (-1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		is_no_redir(t_exec **exe, int what)
{
	t_exec		*tmp;

	tmp = *exe;
	if (what && remaining_redir(&tmp, 2, 0))
		return (0);
	if (!what && remaining_redir(&tmp, 1, 0))
		return (0);
	return (1);
}

void	set_null(t_tok **a, t_exec **b, t_lstag **c)
{
	*a = NULL;
	*b = NULL;
	*c = NULL;
}
