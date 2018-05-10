/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:07 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define TOK_NUM 17
# define TOK_TAB_NUM 13

# include "libmt.h"
# include "list.h"
# include "liberror.h"

/*
** ENUM_TOKEN
*/

typedef enum	e_token
{
	T_SEMICOLON,
	T_DAND,
	T_DPIPE,
	T_GREAT,
	T_LESS,
	T_DGREAT,
	T_PIPE,
	T_DLESS,
	T_AND,
	T_LESSAND,
	T_GREATAND,
	T_EGAL,
	T_COM,
	T_EXPAND,
	T_SPACE,
	T_WORD,
	T_NUM
}				t_token;

/*
** struct t_op:
** ; 0
** & 1
** $ 2
** = 3
** > 4
** < 5
** >> 6
** | 7
** << 8
** && 9
** || 10
** <& 11
** >& 12
** CMD 13
** CMD-ARG 14
** FILE_ARG 15
*/

typedef enum	e_op
{
	OP_SEP,
	OP_AND,
	OP_EXPAND,
	OP_EGAL,
	OP_REDIR_GREAT,
	OP_REDIR_LESS,
	OP_REDIR_DGREAT,
	OP_REDIR_PIPE,
	OP_HEREDOC,
	OP_LOGIC_AND,
	OP_LOGIC_OR,
	OP_AGREG_LESS,
	OP_AGREG_GREAT,
	OP_CMD,
	OP_CMD_ARG,
	OP_FILE_ARG
}				t_op;

/*
** MAIN_FUNCTIONS
*/

t_tok			*parser(t_tok *l_tok);
t_tok			*lexer(char *str);
t_tok			*arg_parsing(char *str, char **tab_token);
t_tok			*format_list(t_tok *lst, char **tok);
t_exec			*create_final_lst(t_tok **lst_tok);
int				parsing_error(t_exec *exe);
int				check_type(int val);
int				add_to_list(t_tok **lst_fin, char **tok);
int				verif_digits(char *tok);
int				verif_op(int type);
int				is_redir(char **tok);
int				is_operator2(char **array, char *tok);
int				verif_char(char c);
int				check_err(t_tok *lst);
int				second_pass(t_tree **ast, t_exec **exec);
int				check_fop(t_exec *exec);
int				final_check(t_exec *exec);
void			precision_sort(t_tree **ast);
void			freelst_ast(t_tree **ast);
void			freelst_exec(t_exec **exec);
void			check_simple_op(t_tok **lst);
void			check_multi_op(t_tok **lst);
void			is_agreg(t_tok **lst);
void			view_ast_lst(t_tree **ast);
void			view_exec_lst(t_exec **exec);
void			process(t_tok *prev, t_tok *act, t_tok **lstx, char **tok);
void			if_operator(t_tok *prev, t_tok *act, t_tok **lstx, char **tok);
void			assign_type(t_tok **prev, t_tok **lst);
char			**get_tab(int val);

#endif
