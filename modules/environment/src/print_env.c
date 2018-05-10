/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:33:28 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:33:30 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

/*
**	\brief	Affichage des variables d'environnement
**
**	\param	environment	- environnement à afficher
**
**	\return	**0** si l'affichage s'est effectué correctement
**			ou **1** en cas d'erreur.
*/

int	print_env(const char **environment)
{
	int	i;

	i = 0;
	if (environment)
		while (environment[i])
			ft_putendl(environment[i++]);
	return (!i);
}
