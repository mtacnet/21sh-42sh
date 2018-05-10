/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:17:28 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:17:29 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isprint() renvoie 1
** si le caractère donné en paramètre est un caractère affichable.
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
