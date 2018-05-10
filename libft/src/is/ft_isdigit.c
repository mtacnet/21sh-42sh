/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:17:20 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:17:21 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isdigit() renvoie 1
** si le caractère donné en paramètre est un chiffre.
*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
