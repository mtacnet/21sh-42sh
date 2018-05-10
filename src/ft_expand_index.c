/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:26:56 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:26:57 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "expansion.h"

/*
**	Cette fonction check si ce qui suit le '!' est un cas d'expansion.
*/

int			ft_after_exclam(char *str)
{
	if (ft_isdigit((str[0] == '-' ? str[1] : str[0])))
		return (1);
	else if (ft_isalpha(str[0]))
		return (1);
	else if (str[0] == '!')
		return (1);
	else
		return (0);
}

/*
**	Cette fonction est utilisee pour retournee les erreurs.
**	Elle affiche un "event not found" sur la sortie d'erreur.
**	Elle affiche aussi l'event concerne.
*/

int			ft_enf(char *cmd, int val)
{
	char	*display;
	int		digit;
	int		i;

	i = (cmd[0] == '-' ? 1 : 0);
	digit = (ft_isdigit(cmd[i]) ? 1 : 0);
	while ((digit ? ft_isdigit(cmd[i]) : ft_isalpha(cmd[i])))
		i++;
	if (!(display = ft_memalloc(sizeof(char) * (i + 2))))
		sh_error_exit(1, "in ft_enf function");
	i = (cmd[0] == '-' ? 1 : 0);
	display[0] = '!';
	if (i)
		display[1] = '-';
	while ((digit ? ft_isdigit(cmd[i]) : ft_isalpha(cmd[i])))
	{
		display[i + 1] = cmd[i];
		i++;
	}
	ft_putstr_fd("ERROR: event not found: ", 2);
	ft_putendl_fd(display, 2);
	ft_strdel(&display);
	return (val);
}

/*
**	Cette fonction permet de faire suivre a l'index la suite des operations
**	apres avoir rencontre un '!' dans la string de depart.
*/

int			ft_end_exclam(char *str)
{
	int		ret;

	ret = 0;
	if (ft_isdigit((str[0] == '-' ? str[1] : str[0])))
		ret += ag_nbrlen(ft_atoi(str));
	else if (ft_isalpha(str[0]))
	{
		while (ft_isalpha(str[ret]))
			ret++;
	}
	else if (str[0] == '!')
		ret++;
	else
		return (1);
	return (ret + 1);
}

/*
**	Meme chose que pour le tild sauf qu'ici c'est pour le dollar.
*/

int			ft_end_dollar(char *str)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (ft_isdigit(str[i]) || str[i] == '?')
		return (1);
	else if (ft_isalpha_und(str[i]))
	{
		while (ft_isalpha_und(str[i]) || ft_isdigit(str[i]))
		{
			i++;
			ret++;
		}
		return (ret);
	}
	return (0);
}
