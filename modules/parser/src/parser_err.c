/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:49:05 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:49:07 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_exec		*compare_id(t_exec *exe, t_exec *prev)
{
	int		i;

	i = 0;
	if (prev->token->token_id == 0 || prev->token->token_id == 1 ||
	prev->token->token_id == 5 || prev->token->token_id == 6 ||
	prev->token->token_id == 8 || prev->token->token_id == 9 ||
	prev->token->token_id == 10 || prev->token->token_id == 11 ||
	prev->token->token_id == 12 || prev->token->token_id == 4)
		i++;
	if (exe->token->token_id == 0 || exe->token->token_id == 1 ||
	exe->token->token_id == 5 || exe->token->token_id == 6 ||
	exe->token->token_id == 8 || exe->token->token_id == 9 ||
	exe->token->token_id == 10 || exe->token->token_id == 11 ||
	exe->token->token_id == 12 || exe->token->token_id == 4 ||
	exe->token->token_id == 7)
		i++;
	if (i == 2)
		return (exe);
	else
		return (NULL);
}

int					parsing_error(t_exec *exe)
{
	t_exec		*head;
	t_exec		*prev;

	head = exe;
	prev = NULL;
	while (exe != NULL)
	{
		if (prev)
			if (compare_id(exe, prev) != NULL)
			{
				ft_putstr_fd("syntax error near unexpected token `", 2);
				ft_putstr_fd(exe->token->token, 2);
				ft_putendl_fd("'", 2);
				return (-1);
			}
		prev = exe;
		exe = exe->next;
	}
	exe = head;
	return (0);
}
