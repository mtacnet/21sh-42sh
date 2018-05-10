/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:29:56 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:29:57 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	exit_final(int exit_val)
{
	char	**built;
	t_tok	**tok;
	t_exec	**exe;
	char	*pwd;

	if ((pwd = beacon_pwd(NULL)))
		ft_strdel(&pwd);
	if ((exe = get_exe(NULL)))
		freelst_exec(exe);
	if ((tok = get_tok(NULL)))
		freelst(tok);
	if (get_env(NULL))
		ag_strdeldouble(get_env(NULL));
	if (get_loc(NULL))
		ag_strdeldouble(get_loc(NULL));
	if (get_history(NULL))
		delete_history_list(get_history(NULL));
	if ((built = get_shbuiltin()))
		ft_memdel((void **)&built);
	get_term(1);
	sh_resetsignal();
	exit(exit_val);
}

int		builtin_exit(char **args)
{
	int		exit_val;
	char	***local;

	if (args && args[0] && args[1])
		return (sh_error_int(17, "exit"));
	if (args && !args[0])
	{
		local = get_loc(NULL);
		exit_val = ft_atoi(ft_getenv("?", (const char **)*local));
	}
	else if (args[0] && ag_isnumber(args[0]))
		exit_val = ft_atoi(args[0]) % 256;
	else
	{
		exit_val = 255;
		ft_putendl_fd("ERROR: numeric argument required", 2);
	}
	exit_final(exit_val);
	return (0);
}
