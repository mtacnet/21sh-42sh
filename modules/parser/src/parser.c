/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:49:03 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:49:05 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** check_op: Prend une string correspondant a un token en parametre.
** Analyse les chars et assigne un numéro qui correspondra au type du token_id.
*/

static int		check_op(char *tok)
{
	int		i;

	i = 0;
	if (tok[0] == 62)
		i = 1;
	else if (tok[0] == 60)
		i = 2;
	if (tok[1])
	{
		if (i == 1 && tok[1] == 62)
			i = 3;
		else if (i == 2 && tok[1] == 60)
			i = 4;
		else if (i == 1 && tok[1] == 38)
			i = 5;
		else if (i == 2 && tok[1] == 38)
			i = 6;
		else
			i = 7;
	}
	return (i);
}

/*
** is_agreg: Prend un pointeur sur maillon en parametre.
** Tant que des chiffres sont rencontrés dans notre chaine on avance puis
** analyse des caracteres suivants les chiffres afin de véfifier s'il s'agit
** d'une aggrégation. Si token_id vaut -1 alors le type n'existe pas.
*/

void			is_agreg(t_tok **tok)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*tok)->token[i] && ft_isdigit((*tok)->token[i]) != 0)
		i++;
	j = check_op(&(*tok)->token[i]);
	if (j == 1)
		(*tok)->token_id = OP_REDIR_GREAT;
	else if (j == 2)
		(*tok)->token_id = OP_REDIR_LESS;
	else if (j == 3)
		(*tok)->token_id = OP_REDIR_DGREAT;
	else if (j == 4)
		(*tok)->token_id = OP_HEREDOC;
	else if (j == 5)
		(*tok)->token_id = OP_AGREG_GREAT;
	else if (j == 6)
		(*tok)->token_id = OP_AGREG_LESS;
	else if (j == 7)
		(*tok)->token_id = -1;
}

/*
** precision: Prend un pointeur sur maillon d'une liste de token en parametre.
** Cette fonction spécifie le type exact des tokens de types opérateurs.
*/

static void		precision_op(t_tok **lst)
{
	int		i;

	i = ft_strlenint((*lst)->token);
	if (i < 2)
		check_simple_op(lst);
	else if (i >= 2)
		check_multi_op(lst);
}

static void		precision_cmd(t_tok **lst, t_tok *prev)
{
	if ((*lst)->token[0] == 45)
		(*lst)->token_id = OP_CMD_ARG;
	if (prev)
		assign_type(&prev, lst);
	else
		(*lst)->token_id = OP_CMD;
}

/*
** PARSER_CORE: Fonction principale qui permet d'effectuer une précision
** syntaxique afin d'obtenir le type exact des tokens
** (ex: token de type operator --> renseignement du type exact de l'operator)
*/

t_tok			*parser(t_tok *l_tok)
{
	t_tok		*head;
	t_tok		*prev;

	head = l_tok;
	prev = NULL;
	while (l_tok != NULL)
	{
		if (l_tok->id == 2)
			precision_op(&l_tok);
		if (l_tok->id == 1)
			precision_cmd(&l_tok, prev);
		prev = l_tok;
		l_tok = l_tok->next;
	}
	l_tok = head;
	if (check_err(l_tok) == -1)
		return (NULL);
	return (l_tok);
}
