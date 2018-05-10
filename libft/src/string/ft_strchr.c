/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:21:25 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:21:26 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strchr() renvoie le pointeur sur le caractère c, trouvé dans la chaîne s.
** Si c n'est pas trouvé dans s, NULL est renvoyé.
*/

char	*ft_strchr(const char *s, int c)
{
	while ((*s != c) && *s)
		s++;
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
