/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:59 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:35:00 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexec.h"

void	add_add(int *a, int b, int *c, int d)
{
	*a = b;
	*c = d;
}

int		return_t_exec(t_exec **a)
{
	if (a || !*a)
		freelst_exec(a);
	return (-1);
}

int		check_for_files(t_exec **exe)
{
	t_exec	*tmp;

	tmp = *exe;
	while (tmp)
	{
		if (tmp && tmp->token && tmp->token->token_id == OP_REDIR_LESS)
		{
			if (tmp->next && tmp->next->token && tmp->next->token->token)
			{
				if (access(tmp->next->token->token, F_OK))
				{
					ft_putstr_fd("ERROR: file opening: ", 2);
					ft_putendl_fd(tmp->next->token->token, 2);
					return (-1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
