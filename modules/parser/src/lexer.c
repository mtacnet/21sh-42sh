/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:58 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:59 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** get_tab: singleton permettant d'avoir accès en permance au tableau des
** opérateurs. Initialisé au premier appel avec val == 1 puis ensuite val == 0.
*/

char	**get_tab(int val)
{
	static char		**tab = NULL;

	if (val == 1)
	{
		if (!(tab = (char**)ft_memalloc(sizeof(char*) * (TOK_TAB_NUM + 1))))
			sh_error_exit(1, "function get_tab");
		tab[T_SEMICOLON] = ";";
		tab[T_DAND] = "&&";
		tab[T_DPIPE] = "||";
		tab[T_GREAT] = ">";
		tab[T_LESS] = "<";
		tab[T_DGREAT] = ">>";
		tab[T_PIPE] = "|";
		tab[T_DLESS] = "<<";
		tab[T_AND] = "&";
		tab[T_LESSAND] = "<&";
		tab[T_GREATAND] = ">&";
		tab[T_EGAL] = "=";
		tab[T_COM] = "#";
	}
	return (tab);
}

/*
** LEXER_CORE: Fonction principale qui permet d'obtenir une liste chainée des
** tokens (cmd et op) à partir d'un char *str.
** La mémoire allouée est libérée avec les ternaires en fin de fonctions
*/

t_tok	*lexer(char *str)
{
	char	**tab_token;
	char	*tok;
	t_tok	*lexer;
	t_tok	*lst_tok;

	if (!(tok = (char*)ft_memalloc(sizeof(char) * 1024)))
		sh_error_exit(1, "function lexer");
	lexer = new_list();
	lst_tok = new_list();
	tab_token = get_tab(1);
	if ((lst_tok = arg_parsing(str, tab_token)) != NULL)
		lexer = format_list(lst_tok, &tok);
	lst_tok ? freelst(&lst_tok) : NULL;
	tab_token ? free(tab_token) : NULL;
	tok ? ft_strdel(&tok) : NULL;
	return (lexer);
}
