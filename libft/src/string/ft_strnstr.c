/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:22:53 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:22:54 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	lenofb;
	unsigned int	lenofl;
	char			*big1;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	lenofb = ft_strlen(big);
	lenofl = ft_strlen(little);
	big1 = (char*)big;
	if (len != 0)
	{
		while ((i + lenofl <= len) && (i + lenofl <= lenofb))
		{
			if (!ft_strncmp(little, &big1[i], ft_strlen(little)))
				return (&big1[i]);
			i++;
		}
	}
	return (NULL);
}
