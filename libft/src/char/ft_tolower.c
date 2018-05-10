/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:16:23 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:16:25 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_tolower() renvoie la lettre qui lui est donnée en paramètre, convertie
** en minuscule.
*/

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
