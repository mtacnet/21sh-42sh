/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:20:10 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:20:11 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Affiche un caractère sur le 'fd' indiqué.
*/

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
