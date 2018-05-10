/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:49:18 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:49:21 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		verif_type_op(int op)
{
	if (op == 0 || op == 1 || op == 3 || op == 7 || op == 9 || op == 10)
		return (0);
	return (1);
}

int				check_fop(t_exec *exec)
{
	t_exec		*tmp;
	t_exec		*prev;

	tmp = exec;
	prev = NULL;
	while (tmp != NULL)
	{
		if (tmp->token->token_id == OP_HEREDOC && tmp->next == NULL)
			return (sh_error_int(19, tmp->token->token));
		if (verif_type_op(tmp->token->token_id) == 0)
		{
			if (prev == NULL)
				return (sh_error_int(19, tmp->token->token));
		}
		if (tmp->token->token_id == 5 && tmp->next == NULL)
			return (sh_error_int(19, tmp->token->token));
		if (tmp->token->token_id == 15 && tmp->token->token[0] == 10 &&
				tmp->next == NULL)
			return (sh_error_int(19, tmp->token->token));
		prev = tmp;
		tmp = tmp->next;
	}
	return (0);
}

/*
** freelst_ast: Parcourt la structure en paramètre et libère la mémoire allouée
** aux maillons de type t_tok *token grace a freelst. Libère ensuite le maillon
** global (free(*ast))
*/

void			freelst_ast(t_tree **ast)
{
	t_tree		*list;
	t_tree		*tmp;

	list = *ast;
	while (list)
	{
		tmp = list->next;
		freelst(&list->token);
		free(list);
		list = tmp;
	}
	*ast = NULL;
}

/*
** freelst_exec: Parcourt la structure en paramètre et libère la mémoire allouée
** pour les maillons de type liste de token grace a la fonction freelst.
** Le maillon principal est ensuite libéré (free(*exec)).
*/

void			freelst_exec(t_exec **exec)
{
	t_exec	*list;
	t_exec	*tmp;

	list = *exec;
	while (list)
	{
		tmp = list->next;
		freelst(&list->token);
		free(list);
		list = tmp;
	}
	*exec = NULL;
}

/*
** assign_type: Vraiment ? Tu veux un dessin ? Aller, un indice, ça à un rapport
** avec une énum dans le parser.h. KDO
*/

void			assign_type(t_tok **prev, t_tok **lst)
{
	if ((*prev)->id == 2)
	{
		if ((*prev)->token_id == OP_SEP || (*prev)->token_id == OP_AND ||
				(*prev)->token_id == OP_REDIR_PIPE ||
				(*prev)->token_id == OP_LOGIC_AND ||
				(*prev)->token_id == OP_LOGIC_OR)
			(*lst)->token_id = OP_CMD;
		else
			(*lst)->token_id = OP_FILE_ARG;
	}
	else if ((*prev)->id == 1)
	{
		if (((*prev)->token_id == OP_CMD_ARG) && ((*lst)->token[0] != 45))
			(*lst)->token_id = OP_FILE_ARG;
		else if (((*prev)->token_id == OP_CMD_ARG) && ((*lst)->token[0] == 45))
			(*lst)->token_id = OP_CMD_ARG;
		else if (((*prev)->token_id == OP_CMD) && ((*lst)->token[0] == 45))
			(*lst)->token_id = OP_CMD_ARG;
		else if (((*prev)->token_id == OP_CMD) && ((*lst)->token[0] != 45))
			(*lst)->token_id = OP_FILE_ARG;
		else if (((*prev)->token_id == OP_FILE_ARG) && ((*lst)->token[0] != 45))
			(*lst)->token_id = OP_FILE_ARG;
		else if (((*prev)->token_id == OP_FILE_ARG) && ((*lst)->token[0] == 45))
			(*lst)->token_id = OP_CMD_ARG;
	}
}
