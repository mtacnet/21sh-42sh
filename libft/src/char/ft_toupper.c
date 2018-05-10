/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:16:36 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:16:38 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_toupper() renvoie la lettre qui lui est donnée en paramètre, convertie
** en majuscule.
*/

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
