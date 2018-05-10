/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_putchoice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:43:17 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:43:19 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_putchoice.c
**	\author	Alexis Guérin
**	\date	22 février 2018
*/

#include "libag.h"

static void	print_simple(const char **dstr)
{
	int	i;

	i = -1;
	while (dstr[++i])
		ft_putendl(dstr[i]);
}

static void	print(const char **dstr, int big, int col)
{
	int	line;
	int	i;

	line = 0;
	i = -1;
	while (dstr[++i])
	{
		if (line + big > col)
		{
			line = 0;
			ft_putendl("");
		}
		line += ft_putstr(dstr[i]);
		line += ag_putxchar(' ', big - ft_strlen(dstr[i]));
	}
	ft_putendl("");
}

static int	big(const char **dstr)
{
	int	i;
	int	len;
	int	tmp;

	i = -1;
	len = 0;
	while (dstr[++i])
		if ((tmp = ft_strlen(dstr[i])) > len)
			len = tmp;
	return (len);
}

/*
**	\brief	Affichage d'une liste de choix en colonne
**
**	Affiche une liste de choix alignés en colonne
**	en fonction de la taille de la fenêtre.
**
**	\param	dstr	- tableau de chaînes contenant les choix à afficher
**
**	\return	**0** en cas de succès ou **1** sinon
*/

int			ag_putchoice(const char **dstr)
{
	int				bigger;
	struct winsize	window;

	if (dstr)
	{
		if (ioctl(0, TIOCGWINSZ, &window) != -1)
		{
			bigger = big(dstr);
			if (bigger + 1 >= window.ws_col)
				print_simple(dstr);
			else
				print(dstr, bigger + 1, window.ws_col);
			return (0);
		}
		else
			ft_putendl_fd("ag_putchoice: ioctl error.", 2);
	}
	return (1);
}
