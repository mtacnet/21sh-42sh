/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:48:39 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:48:40 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** check_type: Retourne le type du token en fonction de la valeur passée
** en paramètre. 1 = op, 2 = space, 3 = word, 4 = num
*/

int				check_type(int val)
{
	if (val >= 0 && val <= 13)
		return (1);
	else if (val == 14)
		return (2);
	else if (val == 15)
		return (3);
	else if (val == 16)
		return (4);
	return (0);
}

/*
** is_operator: Prend un caractere et un tableau de char* en parametre.
** Compare les valeurs du tableau de token au caractere passé en parametre.
** Si la comparaison est valide: return le type d'operateur sinon retourne -1
*/

static int		is_operator(char c, char **tab_token)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (tab_token[i] && tab_token[i][0] != '\0')
	{
		if (c == tab_token[i][0])
		{
			j = i;
			break ;
		}
		i++;
	}
	return (j);
}

/*
** check_char: Prend un caractere et un tableau de char* en parametres.
** Verifie le type du caractere donné en parametre a l'aide des fonctions
** de vérification is_operator et ft_isspace. Retourne le type grace a enum.
*/

static int		check_char(char c, char **tab_token)
{
	int		i;

	if (c == 35)
		return (T_COM);
	i = is_operator(c, tab_token);
	if (i == -1)
	{
		i = ft_isspace(c);
		if (c == '\n')
			i = 0;
		if (i == 0)
		{
			if (ft_isdigit(c) == 1)
				return (T_NUM);
			else
				return (T_WORD);
		}
		else if (i == 1)
			return (T_SPACE);
	}
	else if (i > -1)
		return (i);
	return (0);
}

/*
** check_value: Ajoute chaque caracteres et son type dans la liste lst_tok.
** Cette liste une fois remplie servira a créer la liste final en rassemblant
** les mailons de meme types qui se suivent.
*/

static int		check_value(t_tok **lst_tok, char c, int val)
{
	char	*tmp;

	if (!(tmp = (char*)ft_memalloc(sizeof(char) * 2)))
		sh_error_exit(1, "function check_value");
	tmp[0] = c;
	tmp[1] = '\0';
	if (val >= 0 && (verif_char(c) == 0))
		push_elemx(lst_tok, tmp, val, check_type(val));
	ft_strdel(&tmp);
	return (0);
}

/*
** arg_parsing: Prend une string et un tableau de char* en parametres.
** Parcours la string et compare chaque caracteres afin de pouvoir déterminer
** son type (operator/word/space/num). L'ajout se fait dans une liste temporaire
** nommée lst_tok puis est retourné à la fonction principale 'lexer'.
*/

t_tok			*arg_parsing(char *str, char **tab_token)
{
	int		i;
	int		j;
	t_tok	*lst_tok;

	i = 0;
	j = 0;
	lst_tok = new_list();
	while (str[i] != '\0')
	{
		j = 0;
		j = check_char(str[i], tab_token);
		if (j == T_COM)
			return (lst_tok);
		if (check_value(&lst_tok, str[i], j) == -1)
			sh_error_exit(1, "function arg_parsing");
		i++;
	}
	return (lst_tok);
}
