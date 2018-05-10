/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:59:07 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:49:14 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** move_elem: Déplace un maillon de type CMD_ARG derrière le maillon de tête
** de liste de type CMD. Si un maillon de type CMD_ARG suit déja la tête de
** liste alors le maillon est ajouté après celui-ci.
** Ex: ls -a > txt -l devient ls -a -l > txt
*/

static void		move_elem(t_tok **cmd, t_tok **node, t_tok **node_prev)
{
	t_tok		*tmp;

	tmp = (*cmd);
	if (tmp->next->token_id == OP_CMD_ARG)
		tmp = tmp->next;
	while (tmp && tmp->next && tmp->next->id != 2)
		tmp = tmp->next;
	(*node_prev)->next = (*node)->next;
	(*node)->next = tmp->next;
	tmp->next = (*node);
}

/*
** replace_arg: Vérifie que la tête de liste est de type CMD et procède
** au déplacement du maillon avec la fonction 'move_elem'.
*/

static void		replace_arg(t_tok **head, t_tok **node, t_tok **node_prev)
{
	t_tok		*save;

	save = *head;
	while (*head != NULL)
	{
		if ((*head)->token_id == OP_CMD)
			move_elem(&(*head), node, node_prev);
		*head = (*head)->next;
	}
	*head = save;
}

/*
** sort_list: Effectue un tri dans la liste chainée en paramètre.
** Le tri se fait grace à l'appel de fonction 'replace_arg' et la condition
** qui vérifie le type d'opérateur (CMD ou CMD_ARG)
** Exemple: ls > txt -l devient ls -l > txt
*/

static void		sort_list(t_tok **lst)
{
	t_tok		*head;
	t_tok		*prev;
	t_tok		*pp;

	head = *lst;
	prev = NULL;
	pp = NULL;
	while (*lst)
	{
		if ((*lst)->token_id == OP_CMD_ARG && prev &&
				prev->token_id == OP_FILE_ARG && pp->id == 2)
			replace_arg(&head, &(*lst), &prev);
		pp = prev;
		prev = (*lst);
		*lst = (*lst)->next;
	}
	*lst = head;
}

/*
** precision_sort: Parcourt la structure en paramètre et applique la fonction
** 'sort_list' sur chaque maillons de la structure de type ast->token
** (liste de tokens)
*/

void			precision_sort(t_tree **ast)
{
	t_tree		*head;

	head = *ast;
	while (*ast != NULL)
	{
		if (ft_strcmp("env", (*ast)->token->token) != 0)
			sort_list(&(*ast)->token);
		*ast = (*ast)->next;
	}
	*ast = head;
}
