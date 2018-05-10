/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:41 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:43 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** verif_alloc: Prend en paramètre la chaine dont l'alloc est a vérifier et la
** taille de l'allocation actuelle. Si la chaine *tmp peut encore contenir des
** caractères alors elle est retournée sinon elle est resize à sz_alloc+1024.
*/

static char		*verif_alloc(char *tmp, t_size *sz)
{
	int			i;
	char		*new;

	i = (ft_strlenint(tmp) + 1) % 1024;
	new = NULL;
	if (i == 0)
	{
		if (!(new = (char*)ft_memalloc(sizeof(char) * (sz->sz_alloc + 1024))))
			sh_error_exit(1, "function verif_alloc");
		new = ft_strcpy(new, tmp);
		ft_strdel(&tmp);
		tmp = NULL;
		sz->sz_alloc += 1024;
		return (new);
	}
	return (tmp);
}

/*
** recognize_token: Prend un tableau de token et un token en paramètre.
** A chaque tour de boucle le token est comparé aux valeurs du tableau avec
** ft_strstr. Si match alors return 2 (type opérator) sinon return 1 (type cmd).
*/

static int		recognize_token(char **tab, char *tok)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (tab[i] && tab[i][0] != '\0')
	{
		if (ft_strstr(tok, tab[i]) != NULL)
		{
			ret = 1;
			break ;
		}
		i++;
	}
	if (ret == 1)
		return (2);
	return (1);
}

/*
** add_to_list: Prend une liste et un pointeur sur char* en paramètre.
** La fonction effectue une reconnaissance du token avec la fonction
** 'recognize_token' puis ajoute le token à la liste. Le token est ensuite
** totalement supprimé et recréer à vide pour ensuite accueillir d'autres chars.
*/

int				add_to_list(t_tok **lst_fin, char **tok)
{
	int			val;

	val = recognize_token(get_tab(0), *tok);
	push_elemx(lst_fin, *tok, 0, val);
	ft_strdel(tok);
	if (!(*tok = (char*)ft_memalloc(sizeof(char) * 1024)))
		sh_error_exit(1, "function add_to_list");
	return (0);
}

/*
** format_list: Prend la liste de token temporaire en paramètre.
** Parcourt de la liste temporaire, les maillons pouvant être assemblés sont
** stockés dans *tok avant d'être ajouté à la liste finale (lst_fin). L'ajoute
** se fait grace à la fonction process et ses conditions. La liste finale est
** retournée après la libération des variables allouées.
*/

t_tok			*format_list(t_tok *lst, char **tok)
{
	t_tok		*lst_fin;
	t_tok		*head;
	t_tok		*prev;
	t_size		sz;

	head = lst;
	lst_fin = new_list();
	sz.sz_alloc = 1024;
	prev = NULL;
	while (lst != NULL)
	{
		*tok = verif_alloc(*tok, &sz);
		process(prev, lst, &lst_fin, tok);
		if (lst->token_id != T_SPACE)
			ft_strcat(*tok, lst->token);
		prev = lst;
		if (lst->next == NULL && lst->token_id != T_SPACE)
			add_to_list(&lst_fin, tok);
		lst = lst->next;
	}
	lst = head;
	return (lst_fin);
}
