/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:21 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:22 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libexec.h"

static int		check_in_fd(t_exec *exe)
{
	if (exe->token->token[0] == 62)
		return (1);
	else if (exe->token->token[0] != 62)
		return (ft_atoi(exe->token->token));
	return (0);
}

static int		fd_is_digit(t_exec *next)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (next->token->token[i] != '\0')
	{
		if (ft_isdigit(next->token->token[i]) == 0)
			ret++;
		i++;
	}
	return (ret);
}

static int		is_dash(t_exec *next)
{
	if (next->token->token[0] == 45)
		return (1);
	else
		return (0);
}

static int		check_out_fd(t_exec *act, t_exec *next)
{
	if (next == NULL)
		return (sh_error_int(20, NULL));
	else if (next != NULL && (act->token->token_id == OP_AGREG_GREAT ||
			act->token->token_id == OP_AGREG_LESS))
	{
		if (is_dash(next) == 0)
		{
			if (fd_is_digit(next) > 0)
				return (sh_error_int(21, next->token->token));
			else
				return (ft_atoi(next->token->token));
		}
		else
			return (get_one_sided_pipe());
	}
	else if (next != NULL && (act->token->token_id == OP_REDIR_GREAT ||
			act->token->token_id == OP_REDIR_DGREAT))
		return (open_file2(next, act));
	return (0);
}

int				get_fd(t_exec **exe, int val)
{
	t_exec		*tmp;
	int			ret;

	tmp = *exe;
	ret = 0;
	if (tmp->token->token_id == OP_REDIR_GREAT ||
			tmp->token->token_id == OP_REDIR_DGREAT ||
			tmp->token->token_id == OP_REDIR_LESS ||
			tmp->token->token_id == OP_AGREG_GREAT ||
			tmp->token->token_id == OP_AGREG_LESS)
	{
		if (val == 1)
			ret = check_in_fd(tmp);
		else if (val == 2)
			ret = check_out_fd(tmp, tmp->next);
	}
	return (ret);
}
