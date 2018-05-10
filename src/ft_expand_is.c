/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:27:02 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:27:05 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "expansion.h"

/*
**	Banales fonctions de reconnaissance de char.
*/

int		ft_isredir(int c)
{
	if (c == '<')
		return (1);
	else if (c == '>')
		return (2);
	else if (c == '&')
		return (3);
	else if (c == ';')
		return (4);
	else if (c == '|')
		return (5);
	return (0);
}

int		ft_isalpha_und(int c)
{
	if (ft_isalpha(c))
		return (1);
	else if (c == '_')
		return (1);
	else
		return (0);
}

int		ft_aft_dol(char *str)
{
	if (ft_isdigit(str[0]))
		return (1);
	else if (ft_isalpha_und(str[0]))
		return (1);
	else if (str[0] == '?')
		return (1);
	else
		return (0);
}

/*
**	Les deux fonctions qui suivent servent a identifier les cas ou l'on
**	replace le '~' dans notre ligne de commande.
**
**	la premiere check si se qu'il y a avant le tild est valide.
**	la second check se qu'il y a apres.
*/

int		check_before(char *str, int index)
{
	if (str[index] == '~')
	{
		if (!index)
			return (1);
		index--;
		if (ft_isredir(str[index]) || ft_isspace(str[index]))
		{
			while (ft_isspace(str[index]) && index)
				index--;
			if (ft_isredir(str[index]))
			{
				if (ft_isredir(str[index]) == 1 && index)
				{
					if (ft_isredir(str[index - 1]) == 1)
						return (0);
				}
			}
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int		tild_k(char *str, int i, int tild)
{
	if (str[i] == '~' && check_before(str, i) && tild)
	{
		i++;
		if (str[i] == '/')
			return (1);
		else if (ft_isspace(str[i]))
			return (1);
		else if (!str[i])
			return (1);
		else if (ft_isredir(str[i]))
			return (1);
		else
			return (0);
	}
	return (0);
}
