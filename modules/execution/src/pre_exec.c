/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:30 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:31 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexec.h"

static void		del(void *content, size_t size)
{
	(void)size;
	if (content)
		ft_memdel(&content);
}

t_exec			**get_exe(t_exec **exe)
{
	static t_exec	**stock = NULL;

	if (exe)
		stock = exe;
	return (stock);
}

t_tok			**get_tok(t_tok **tok)
{
	static t_tok	**stock = NULL;

	if (tok)
		stock = tok;
	return (stock);
}

/*
**	\brief	Lexing/parsing puis appel de l'exécution
*/

static int		pre_exec1(t_tok **token, t_exec **exe, char ***env, t_lstag *hd)
{
	get_tok(token);
	get_exe(exe);
	if (put_here_in_list(exe, &hd) == -1)
	{
		exe ? freelst_exec(exe) : NULL;
		return (-1);
	}
	if (exec(exe, env) == -1)
	{
		exe ? freelst_exec(exe) : NULL;
		return (-1);
	}
	return (0);
}

int				pre_exec(char *line, char ***env, int ret)
{
	t_tok		*token;
	t_exec		*exe;
	t_lstag		*hd;

	set_null(&token, &exe, &hd);
	if (line && (token = lexer(line)))
	{
		if (parser(token) == NULL)
			return (return_free_lst(token));
		if (!(exe = create_final_lst(&token)))
			return (return_free_lst(token));
		if (parsing_error(exe) == -1)
			return (return_free_exec(&exe));
		if (!heredoc(line, &hd, get_shbuiltin()))
			ret = pre_exec1(&token, &exe, env, hd);
		else
			exe ? freelst_exec(&exe) : NULL;
		hd ? ag_lstdel(&hd, del) : NULL;
		if (ret)
			return (-1);
		if (token)
			freelst(&token);
	}
	return (0);
}
