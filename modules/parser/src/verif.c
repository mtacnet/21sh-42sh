/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:49:22 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:49:27 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** verif_op: verifie le type de l'operateur actuel
** retourne 1 si c'est une redirection ou 0 si autres
*/

int		verif_op(int type)
{
	if (type == T_GREAT || type == T_LESS || type == T_EGAL)
		return (1);
	else
		return (0);
}

/*
** verif_digits: Parcourt la str qui contient les caracteres prêt à etre ajoutés
** dans la liste. Si ft_isdigit retourne 0 alors tok ne contient pas uniquement
** des chiffres.
*/

int		verif_digits(char *tok)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (tok[i] != '\0')
	{
		j = ft_isdigit(tok[i]);
		if (j == 0)
			break ;
		i++;
	}
	if (j == 0)
		return (1);
	return (0);
}

/*
** is_operator2: Parcourt le tableau de token et vérifie si la string tok
** correspond aux valeurs du tableau. Return 1 si négatif, 0 si positif.
*/

int		is_operator2(char **tab_token, char *tok)
{
	int		i;
	int		ret;

	i = 0;
	ret = -1;
	while (tab_token[i] && tab_token[i][0] != '\0')
	{
		if (ft_strcmp(tok, tab_token[i]) == 0)
			ret = i;
		i++;
	}
	if (ret == -1)
		return (1);
	return (0);
}

/*
** is_redir: Détermine si le pointeur sur char* en paramètre est un opérateur
** de type redirection ou non. Selection des 2 derniers caractères de char *tok
** ajout dans tmp puis comparaison avec le tableau de token.
** Return 1 si OP_REDIR sinon return 0.
*/

int		is_redir(char **tok)
{
	char	*tmp;
	int		i;
	int		ret;

	tmp = NULL;
	i = ft_strlen(*tok);
	ret = -1;
	if (i >= 2)
	{
		tmp = ft_strsub(*tok, i - 2, i);
		i = 0;
		if (tmp)
		{
			ret = is_operator2(get_tab(0), tmp);
			if (ret == 0)
			{
				ft_strdel(&tmp);
				return (1);
			}
		}
		ft_strdel(&tmp);
	}
	return (0);
}

/*
** process: Procède à l'analyse lexicale en fonction des règles de la
** grammaire POSIX. Lors de l'analyse, le type du caractères précédent est pris
** en compte (prev). Selon le type du caractères actuel (act) et la condition
** alors: ajout du token dans la liste finale afin de faire une délimitation OU
** le caractere est retourné à la fonction appelante afin d'être ajouté au token
** actuel.
*/

void	process(t_tok *prev, t_tok *act, t_tok **lstx, char **tok)
{
	if (prev)
	{
		if (prev->id == 1)
			if_operator(prev, act, lstx, tok);
		if (prev->id == 4)
		{
			if (act->token_id == T_SPACE)
				add_to_list(lstx, tok);
			else if (act->id == 1)
				if ((verif_digits(*tok) != 0) && (verif_op(act->token_id) != 1))
					add_to_list(lstx, tok);
		}
		else if (prev->id == 3)
			if (act->token_id == T_SPACE ||
					(act->id == 1 && act->token_id != T_EGAL))
				add_to_list(lstx, tok);
	}
}
