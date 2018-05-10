/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:17:15 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:17:16 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isascii() renvoie 1
** si le caractère donné en paramètre fait partie de la table ASCII.
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
