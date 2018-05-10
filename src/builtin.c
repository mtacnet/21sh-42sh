/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:26:34 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:26:35 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**	\brief	Tableau indiquant les builtins du projet
**
**	La fonction renvoie un tableau dont chaque case contient le nom
**	d'un builtin du projet.
**	Seule la première dimension est allouée dynamiquement.
**
**	\return	**tableau** contenant le nom des builtins
**			ou **NULL** en cas d'erreur
*/

char	**get_shbuiltin(void)
{
	static char	**t = NULL;

	if (!t)
	{
		if ((t = (char**)ft_memalloc(sizeof(char*) * 8)))
		{
			t[0] = "cd";
			t[1] = "echo";
			t[2] = "env";
			t[3] = "exit";
			t[4] = "history";
			t[5] = "setenv";
			t[6] = "unsetenv";
		}
		else
			sh_error_exit(1, "in function shget_builtin");
	}
	return (t);
}
