/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:49:15 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:49:17 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** check_simple_op: Effectue une vérification syntaxique sur un maillon de liste
*/

void	check_simple_op(t_tok **lst)
{
	if (ft_strncmp((*lst)->token, ";", 1) == 0)
		(*lst)->token_id = OP_SEP;
	else if (ft_strncmp((*lst)->token, "&", 1) == 0)
		(*lst)->token_id = OP_AND;
	else if (ft_strncmp((*lst)->token, ">", 1) == 0)
		(*lst)->token_id = OP_REDIR_GREAT;
	else if (ft_strncmp((*lst)->token, "<", 1) == 0)
		(*lst)->token_id = OP_REDIR_LESS;
	else if (ft_strncmp((*lst)->token, "|", 1) == 0)
		(*lst)->token_id = OP_REDIR_PIPE;
	else if (ft_strncmp((*lst)->token, "$", 1) == 0)
		(*lst)->token_id = OP_EXPAND;
}

/*
** check_multi_op: Effectue une vérification syntaxique sur un maillon de liste
*/

void	check_multi_op(t_tok **lst)
{
	if (ft_isdigit((*lst)->token[0]) == 1)
		is_agreg(lst);
	else
	{
		if (ft_strstr((*lst)->token, "=") != NULL)
			(*lst)->token_id = OP_EGAL;
		else if (ft_strncmp((*lst)->token, "$", 1) == 0)
			(*lst)->token_id = OP_EXPAND;
		else if (ft_strncmp((*lst)->token, ">&", 2) == 0)
			(*lst)->token_id = OP_AGREG_GREAT;
		else if (ft_strncmp((*lst)->token, "<&", 2) == 0)
			(*lst)->token_id = OP_AGREG_LESS;
		else if (ft_strncmp((*lst)->token, "||", 2) == 0)
			(*lst)->token_id = OP_LOGIC_OR;
		else if (ft_strncmp((*lst)->token, "&&", 2) == 0)
			(*lst)->token_id = OP_LOGIC_AND;
		else if (ft_strncmp((*lst)->token, ">>", 2) == 0)
			(*lst)->token_id = OP_REDIR_DGREAT;
		else if (ft_strncmp((*lst)->token, "<<", 2) == 0)
			(*lst)->token_id = OP_HEREDOC;
		else
			(*lst)->token_id = -1;
	}
}

/*
** verif_char: Vérifie si le caractère en paramètre correspond a l'un des
** codes ASCII suivant: " ou ' ou ( ou ) ou [ ou ] ou ` ou { ou }
** Return 1 si le char correspond. Si return 1 alors le char sera par la suite
** totalement ignoré par le lexer/parser.
*/

int		verif_char(char c)
{
	if (c == 34 || c == 39 || c == 40 || c == 41 || c == 91 || c == 93 ||
		c == 96 || c == 123 || c == 125)
		return (1);
	else
		return (0);
}

/*
** if_operator: Effectue des vérifications sur le type d'un opérateur, si les
** tests réussissent alors le token est ajouté dans la liste lstx en paramètre.
*/

void	if_operator(t_tok *prev, t_tok *act, t_tok **lstx, char **tok)
{
	if (prev->token_id != T_EXPAND && prev->token_id != T_EGAL &&
			prev->token_id != T_SEMICOLON)
	{
		if (act->id == 2 || act->id == 3 || act->id == 4)
			add_to_list(lstx, tok);
		else if (act->id == 1)
			if (is_redir(tok) == 1)
				add_to_list(lstx, tok);
	}
	else if (prev->token_id == T_EGAL)
	{
		if (act->token_id == T_SPACE ||
				(act->id == 1 && act->token_id != T_EXPAND))
			add_to_list(lstx, tok);
	}
	else if (prev->token_id == T_SEMICOLON)
	{
		if (act->id == 1 || act->id == 2 || act->id == 3 || act->id == 4)
			add_to_list(lstx, tok);
	}
	else if (prev->token_id == T_EXPAND)
		if (act->token_id == T_SPACE)
			add_to_list(lstx, tok);
}

/*
** check_err: Parcourt la liste en paramètre et vérifie le type de chaque
** maillons. Si un token n'a pu être identifié alors il contient une valeur de
** -1. Dans ce cas une erreur est signalée par un message et la fonction
** renvoie une valeur de -1 ce qui stoppera le lexer/parser.
*/

int		check_err(t_tok *lst)
{
	t_tok	*head;

	head = lst;
	while (lst != NULL)
	{
		if (lst->token_id == -1)
		{
			ft_putstr_fd("parse error: `", 2);
			ft_putstr_fd(lst->token, 2);
			ft_putendl_fd("'", 2);
			return (-1);
		}
		lst = lst->next;
	}
	lst = head;
	return (0);
}
