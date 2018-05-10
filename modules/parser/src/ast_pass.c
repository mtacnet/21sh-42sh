/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:37 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:38 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** view_exec_lst: Parcourt la structure en paramètre et affiche le contenu des
** maillons de type t_tok *token grace a la fonction view_list.
*/

void			view_exec_lst(t_exec **exec)
{
	t_exec		*head;
	int			i;

	i = 1;
	head = *exec;
	while ((*exec) != NULL)
	{
		ft_putendl("");
		ft_putstr("List ");
		ft_putnbr(i);
		ft_putchar('\n');
		view_list(&(*exec)->token);
		if ((*exec)->next != NULL)
			ft_putchar('\n');
		i++;
		*exec = (*exec)->next;
	}
	*exec = head;
}

/*
** if_op3: Vérification syntaxique sur le type du token actuel et précédent.
*/

static int		if_op2(t_exec **exec, t_tok *lst, t_tok *prev)
{
	if (((*exec)->token) && ((lst->token_id == 4 || lst->token_id == 5 ||
					lst->token_id == 6 || lst->token_id == 8 ||
					lst->token_id == 11 || lst->token_id == 12) || (!prev ||
					(prev && (prev->token_id == 4 || prev->token_id == 5 ||
					prev->token_id == 6 || prev->token_id == 8 ||
					prev->token_id == 11 || prev->token_id == 12)))))
		return (1);
	return (0);
}

/*
** if_op3: Vérification syntaxique sur le type du token actuel et précédent.
*/

static int		if_op3(t_exec **exec, t_tok *lst, t_tok *prev)
{
	if (((*exec)->token) && ((lst->token_id == 9 || lst->token_id == 10 ||
					lst->token_id == 0 || lst->token_id == 1 ||
					lst->token_id == 7) || (!prev || (prev &&
						(prev->token_id == 9 || prev->token_id == 10 ||
						prev->token_id == 0 || prev->token_id == 1 ||
						prev->token_id == 7)))))
		return (1);
	return (0);
}

/*
** sort_ast: Parcourt la liste contenue dans le maillon de la struct ast.
** Applique des fonctions de vérifications syntaxique grace à if_op2 et if_op3.
** Si ses fonctions return 1 alors un nouveau maillon est créer dans la struct
** exec et le contenu du token est ajouté.
*/

static int		sort_ast(t_tok *lst, t_exec **exec)
{
	t_tok		*prev;

	prev = NULL;
	while (lst != NULL)
	{
		if (if_op2(exec, lst, prev) == 1)
		{
			if (!((*exec)->next = (t_exec*)ft_memalloc(sizeof(t_exec))))
				return (sh_error_int(1, "function sort_ast"));
			*exec = (*exec)->next;
		}
		if (if_op3(exec, lst, prev) == 1)
		{
			if (!((*exec)->next = (t_exec*)ft_memalloc(sizeof(t_exec))))
				return (sh_error_int(1, "function sort_ast"));
			*exec = (*exec)->next;
		}
		push_elemx(&(*exec)->token, lst->token, lst->token_id, lst->id);
		prev = lst;
		lst = lst->next;
	}
	return (0);
}

/*
** second_pass: Parcourt la struct ast et applique la fonction 'sort_ast' sur
** chaque maillons de type t_tok *token. Le résultat est stockée dans la struct
** exec.
*/

int				second_pass(t_tree **ast, t_exec **exec)
{
	t_tree		*head;

	head = *ast;
	while (*ast != NULL)
	{
		if (sort_ast((*ast)->token, exec) == -1)
			return (sh_error_int(1, "function second_pass"));
		*ast = (*ast)->next;
	}
	*ast = head;
	return (0);
}
