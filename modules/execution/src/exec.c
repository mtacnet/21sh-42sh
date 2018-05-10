/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:14 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:15 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexec.h"
#include <signal.h>

int				expanse_pre_exec(t_exec **exe)
{
	t_exec		*tmp;
	t_tok		*tok;

	if (!exe)
		return (1);
	tmp = *exe;
	while (tmp)
	{
		tok = tmp->token;
		while (tok)
		{
			if (ft_expand_dollar(&(tok->token), (const char**)*get_env(NULL),
									(const char**)*get_loc(NULL), 1))
				return (1);
			tok = tok->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

static int		call_exec(t_exec **exe, char ***env)
{
	int			ret;
	int			op;
	t_exec		*logic;

	ret = -1;
	op = 0;
	while (exe && *exe)
	{
		logic = split_logic(exe);
		expanse_pre_exec(exe);
		if ((ret == -1) || (!ret && op == OP_LOGIC_AND)
						|| (ret && op == OP_LOGIC_OR))
			ret = execution(exe, 0, env);
		freelst_exec(exe);
		if (logic)
		{
			op = logic->token ? logic->token->token_id : op;
			*exe = logic->next;
			logic->next = NULL;
			freelst_exec(&logic);
		}
	}
	return (ret);
}

int				exec(t_exec **exe, char ***env)
{
	t_exec		*nxt_cmd;

	while (exe && *exe)
	{
		nxt_cmd = split_sep(exe);
		if (check_for_files(exe) == -1)
		{
			exe ? freelst_exec(exe) : NULL;
			return (-1);
		}
		get_exe(&nxt_cmd);
		call_exec(exe, env);
		*exe = nxt_cmd;
	}
	return (0);
}
