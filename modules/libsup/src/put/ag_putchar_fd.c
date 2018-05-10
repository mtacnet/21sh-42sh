/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:43:13 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:43:15 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_putchar_fd.c
**	\author	Alexis Guérin
**	\date	2 février 2018
**
**	\brief	Écriture d'un caractère sur un `fd`.
*/

#include "libag.h"

/*
**	\brief	Écriture d'un caractère sur un `fd` suivi d'un retour à la ligne
**
**	Écrit le caractère `c` suivi d'un retour à la ligne sur le descripteur
**	de fichier `fd`.
**
**	\param	c	- caractère
**	\param	fd	- descripteur de fichier
**
**	\return	**nombre de caractères affichés**
*/

int	ag_putcharl_fd(char c, int fd)
{
	return (ft_putchar_fd(c, fd) + ft_putchar_fd('\n', fd));
}

/*
**	\brief	Écriture d'un caractère sur un `fd` suivi d'un espace
**
**	Écrit le caractère `c` suivi d'un espace sur le descripteur de fichier `fd`.
**
**	\param	c	- caractère
**	\param	fd	- descripteur de fichier
**
**	\return	**nombre de caractères affichés**
*/

int	ag_putchars_fd(char c, int fd)
{
	return (ft_putchar_fd(c, fd) + ft_putchar_fd(' ', fd));
}
