/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:38:03 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:38:05 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	open.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Ouverture ou création du fichier d'historique
*/

#include "history.h"

static int	create_file(char *path)
{
	int	fd;

	if ((fd = open(path, O_RDWR | O_CREAT, S_IRUSR + S_IWUSR)) == -1)
		sh_error(5, "in function history: open_history");
	return (fd);
}

static int	open_file(char *path, int perm)
{
	int	flag;
	int	fd;

	if (perm == 10)
		flag = O_RDONLY;
	else if (perm == 100)
		flag = O_WRONLY;
	else
		flag = O_RDWR;
	fd = open(path, flag | O_APPEND);
	return (fd);
}

/*
**	\brief	Ouverture du fichier d'historique
**
**	\param	path	- chemin d'accès au fichier
**
**	\return	**descripteur de fichier** en cas de succès d'ouverture ou
**			ou de création du fichier, ou **-1** sinon.
*/

int			open_history(char *path)
{
	int	fd;
	int	perm;

	fd = -1;
	if (path)
	{
		perm = 0;
		if (!access(path, F_OK))
		{
			if (!access(path, R_OK))
				perm += 10;
			if (!access(path, W_OK))
				perm += 100;
			if (perm)
				fd = open_file(path, perm);
		}
		else
			fd = create_file(path);
	}
	return (fd);
}
