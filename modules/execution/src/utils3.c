/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:53 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:56 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexec.h"

int		set_here(int f1, int f2, int f3)
{
	close(f1);
	dup2(f2, f3);
	close(f2);
	return (0);
}

int		count_file(t_exec **exe)
{
	int		i;
	t_exec	*tmp;

	i = 0;
	tmp = *exe;
	while (tmp != NULL)
	{
		if (tmp->token->token_id == OP_FILE_ARG)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int		get_one_sided_pipe(void)
{
	int		p[2];

	if ((pipe(p)))
		return (-1);
	close(p[1]);
	return (p[0]);
}

void	equal(t_exec **a, t_exec *b, t_exec **c, t_exec *d)
{
	*a = b;
	*c = d;
}

int		return_free_lst(t_tok *token)
{
	freelst(&token);
	return (-1);
}
