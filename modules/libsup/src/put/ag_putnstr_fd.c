/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:43:31 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:43:33 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	ag_putnstr_fd.c
**	\author	Alexis Guérin
**	\date	21 mars 2018
**
**	\brief	Écriture d'un nombre limité de caractères sur un `fd`
*/

#include "libag.h"

/*
**	\brief	Écriture de `n` caractères d'une chaîne sur un `fd`
**
**	ft_putnstr_fd() écrit les `n` premiers caractères de la chaîne `str`.
**	Si `n` est plus grand que la taille de la chaîne, l'affichage s'arrête
**	en fin de chaîne.
**	La fonction renvoie le nombre de caractères affichés.
**
**	\param	str	- chaîne
**	\param	n	- nombre de caractères à afficher
**	\param	fd	- descripteur de fichier où écrire
**
**	\return	**nombre de caractères affichés** ou **-1** en cas d'erreur
*/

int	ag_putnstr_fd(const char *str, unsigned int n, int fd)
{
	unsigned int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len] && len <= n)
		len++;
	if (n > len)
		n = len;
	return (write(fd, str, n));
}

/*
**	\brief	Écriture de `n` caractères d'une chaîne suivi
**			d'un retour à la ligne sur un `fd`
**
**	ft_putnstr_fd() affiche les `n` premiers caractères de la chaîne `str` suivi
**	d'un retour à la ligne.
**	Si `n` est plus grand que la taille de la chaîne, l'affichage s'arrête
**	en fin de chaîne.
**	La fonction renvoie le nombre de caractères affichés.
**
**	\param	str	- chaîne
**	\param	n	- nombre de caractères à afficher
**	\param	fd	- descripteur de fichier où écrire
**
**	\return	**nombre de caractères affichés** ou **-1** en cas d'erreur
*/

int	ag_putnstrl_fd(const char *str, unsigned int n, int fd)
{
	return (ag_putnstr_fd(str, n, fd) + ft_putchar_fd('\n', fd));
}

/*
**	\brief	Écriture des `n` caractères d'une chaîne suivi
**			d'un espace sur un `fd`
**
**	ft_putnstr_fd() affiche les `n` premiers caractères de la chaîne `str` suivi
**	d'un espace.
**	Si `n` est plus grand que la taille de la chaîne, l'affichage s'arrête
**	en fin de chaîne.
**	La fonction renvoie le nombre de caractères affichés.
**
**	\param	str	- chaîne
**	\param	n	- nombre de caractères à afficher
**	\param	fd	- descripteur de fichier où écrire
**
**	\return	**nombre de caractères affichés** ou **-1** en cas d'erreur
*/

int	ag_putnstrs_fd(const char *str, unsigned int n, int fd)
{
	return (ag_putnstr_fd(str, n, fd) + ft_putchar_fd(' ', fd));
}
