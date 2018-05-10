/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:20:05 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:20:06 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Affiche un caractère sur la sortie standard.
*/

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
