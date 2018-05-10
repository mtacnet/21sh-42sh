/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:33 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:36 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** view_ast_lst: Parcourt la structure en paramètre et affiche le contenu des
** maillons de type t_tok *token grace a la fonction view_list.
*/

void			view_ast_lst(t_tree **ast)
{
	t_tree		*head;
	int			i;

	i = 1;
	head = *ast;
	while ((*ast) != NULL)
	{
		ft_putstr("List ");
		ft_putnbr(i);
		ft_putchar('\n');
		view_list(&(*ast)->token);
		if ((*ast)->next != NULL)
			ft_putchar('\n');
		i++;
		*ast = (*ast)->next;
	}
	*ast = head;
}

/*
** if_op: Vérifie le type du token actuel (lst) ainsi que celui du précédent
** (prev) afin de déterminer si l'on doit créer une nouvelle liste à la struc
** ast. Premiere analyse syntaxique des tokens de séparation: &&, ||, ;, &, |
*/

static int		if_op(t_tree **ast, t_tok *lst, t_tok *prev)
{
	if (((*ast)->token) && ((lst->token_id == 9 || lst->token_id == 10 ||
					lst->token_id == 0 || lst->token_id == 1 ||
					lst->token_id == 7) || (prev && (prev->token_id == 9 ||
							prev->token_id == 10 || prev->token_id == 0 ||
							prev->token_id == 1 || prev->token_id == 7))))
		return (1);
	return (0);
}

/*
** first_pass: Parcourt la liste chainée de tokens créer précédemment et
** vérifie le type de chaque token avec la fonction if_op. Si la fonction
** return 1 alors un nouveau maillon est ajouté a la structure ast.
*/

static int		first_pass(t_tok *lst, t_tree **ast)
{
	t_tok	*prev;
	t_tree	*head;

	prev = NULL;
	head = *ast;
	while (lst != NULL)
	{
		if (if_op(ast, lst, prev) == 1)
		{
			if (!((*ast)->next = (t_tree*)ft_memalloc(sizeof(t_tree))))
				sh_error_exit(1, "function first_pass");
			*ast = (*ast)->next;
		}
		push_elemx(&(*ast)->token, lst->token, lst->token_id, lst->id);
		prev = lst;
		lst = lst->next;
	}
	*ast = head;
	return (0);
}

/*
** PARSER_CORE: Fonction principale qui permet d'obtenir une structure contenant
** plusieurs maillons de type t_tok *token (liste chainée de tokens).
** A la fin de cette fonction on obtient une structure contenant  plusieurs
** listes chainées de tokens correspondant à des commandes ou des opérateurs.
** Les listes seront parcouruent lors de l'éxécution.
** Desc: Une first_pass est effectuée et permet d'épurer la liste de tokens
** créée par le lexer. La liste est divisée en plusieurs lst.
** Un tri des arguments contenus dans les lst est fait par precision_sort.
** Une second_pass est effetuée sur les listes créées lors de la first_pass
** afin d'obtenir des 'sous listes' lors d'une saisie d'une cmd complète.
** (Ex: List1 type CMD, List2 type OP, List3 type CMD etc.)
*/

static t_exec	*create_final_lst2(t_tree **ast, t_exec **exec, t_exec **head)
{
	if (second_pass(ast, exec) == -1)
	{
		freelst_ast(&(*ast));
		freelst_exec(&(*exec));
		return (sh_error(1, "function create_final_lst"));
	}
	*exec = *head;
	freelst_ast(&(*ast));
	if (check_fop(*exec) == -1)
	{
		freelst_exec(&(*exec));
		return (NULL);
	}
	return (*exec);
}

t_exec			*create_final_lst(t_tok **lst)
{
	t_tree		*ast;
	t_exec		*exec;
	t_exec		*head;

	if (!(exec = (t_exec*)ft_memalloc(sizeof(t_exec))))
		sh_error_exit(1, "function create_final_lst");
	head = exec;
	if (!(ast = (t_tree*)ft_memalloc(sizeof(t_tree))))
		sh_error_exit(1, "function create_final_lst");
	if (first_pass(*lst, &ast) == -1)
	{
		freelst(lst);
		freelst_ast(&ast);
		return (sh_error(1, "function create_final_lst"));
	}
	freelst(lst);
	lst = NULL;
	precision_sort(&ast);
	return (create_final_lst2(&ast, &exec, &head));
}
