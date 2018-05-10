/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:21:50 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:21:50 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strdup() alloue la mémoire nécessaire pour pouvoir copier 's1' dans une
** nouvelle chaîne.
*/

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*s;

	if (s1)
	{
		size = ft_strlen((char*)s1);
		s = (char*)malloc(sizeof(char) * size + 1);
		if (s)
		{
			i = 0;
			while (s1[i] != '\0')
			{
				s[i] = s1[i];
				i++;
			}
			s[i] = '\0';
			return (s);
		}
	}
	return (NULL);
}
