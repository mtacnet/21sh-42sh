/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:01 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:03 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

/*
** SIZE_STRUCT
*/

typedef struct		s_size
{
	int				sz_alloc;
}					t_size;

/*
** TOKEN_STRUCT
** id = 1 si CMD | 2 si OP
** token_id est à 0 car il n'est utilisé que lors du premier parsing de l'arg
*/

typedef struct		s_tok
{
	int				id;
	int				token_id;
	char			*token;
	struct s_tok	*next;
}					t_tok;

/*
** AST_STRUCT
*/

typedef struct		s_tree
{
	t_tok			*token;
	struct s_tree	*next;
}					t_tree;

/*
** FINAL_LST_EXEC
*/

typedef struct		s_exec
{
	t_tok			*token;
	struct s_exec	*next;
}					t_exec;

/*
** LIST_FUNCTIONS
*/

t_tok				*new_list(void);
t_tok				*init_element(t_tok *element);
void				push_elemx(t_tok **lst, char *content, int token_id,
						int id);
void				push_elem(t_tok **lst, char *content);
void				supp_elem(t_tok **lst, char *arg);
void				push_back(t_tok **lst, char *content);
void				view_list(t_tok **lst);
void				view_llist(t_tok **lst);
void				cpy_lst(t_tok **lst_dest, t_tok **lst_src);
void				freelst(t_tok **lst);
int					is_empty(t_tok **lst);

/*
** FONCTIONS ARRAY
*/

char				**list_to_tab(t_tok **lst);
void				tab_to_list(t_tok **lst, char **array);

#endif
