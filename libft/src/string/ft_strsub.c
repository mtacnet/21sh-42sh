/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:23:13 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:23:14 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s)
	{
		str = (char*)ft_memalloc(sizeof(char) * (len + 1));
		if (str)
		{
			i = 0;
			while (len > 0)
			{
				str[i] = s[start];
				start++;
				len--;
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
