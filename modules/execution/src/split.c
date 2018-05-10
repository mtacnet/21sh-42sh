/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:38 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:39 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexec.h"

/*
**	Retourne la prochaine tete de liste a adopter en cas de separateur,
**	ou null s'il n'y en a pas.
*/

t_exec	*split_sep(t_exec **exe)
{
	t_exec	*tmp;
	t_exec	*prev;
	t_exec	*next;

	if (!exe || !*exe)
		return (NULL);
	tmp = *exe;
	prev = NULL;
	next = NULL;
	while (tmp && tmp->token && tmp->token->token_id != OP_SEP)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev ? prev->next = NULL : NULL;
	if (tmp)
	{
		next = tmp->next;
		tmp->next = NULL;
		freelst_exec(&tmp);
		if (!prev && exe && *exe)
			*exe = (*exe)->next;
	}
	return (next);
}

/*
**	Retourne le prochain operateur logique, ou null s'il n'y en a pas.
**	Cette fonction met à NULL le `next` de l'élément précédent l'opérateur
*/

t_exec	*split_logic(t_exec **exe)
{
	t_exec	*tmp;
	t_exec	*prev;

	if (!exe || !*exe)
		return (NULL);
	tmp = *exe;
	prev = NULL;
	while (tmp && tmp->token && ((tmp->token->token_id != OP_LOGIC_OR &&
						tmp->token->token_id != OP_LOGIC_AND)))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev ? prev->next = NULL : NULL;
	return (tmp);
}

t_exec	*split_pipe(t_exec **exe)
{
	t_exec	*last;
	t_exec	*tmp;
	t_exec	*prev;
	t_exec	*prev2;

	if (!exe || !*exe)
		return (NULL);
	last = NULL;
	tmp = *exe;
	while (tmp)
	{
		if (tmp->token && tmp->token->token_id == OP_REDIR_PIPE)
			equal(&prev2, prev, &last, tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	if (last)
	{
		prev2 ? prev2->next = NULL : NULL;
		equal(&tmp, last->next, &last->next, NULL);
		freelst_exec(&last);
		last = tmp;
	}
	return (last);
}
