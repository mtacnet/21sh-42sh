/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:23:17 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:23:19 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue et retourne une copie de la chaîne passée en paramètre sans les
** espaces blancs au debut et à la fin de cette chaîne. On considère comme
** espaces blancs les caractères ’ ’, ’\n’ et ’\t’.
** Si 's' ne contient passée d’espaces blancs au début ou à la fin,
** la fonction renvoie une copie de 's'.
** Si l’allocation echoue, la fonction renvoie NULL.
*/

static int	ft_trim_space(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	ft_start_end(char const *s, unsigned int *start, unsigned int *end)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	while (ft_trim_space(s[i]) && i < len)
		i++;
	if (i == len)
		return (0);
	*start = i;
	i = len - 1;
	while (ft_trim_space(s[i]) && i > 0)
		i--;
	*end = i;
	return (1);
}

static char	*ft_strnull(void)
{
	char	*str;

	str = (char*)ft_memalloc(sizeof(char) * 2);
	if (str)
	{
		ft_strcpy(str, "");
		return (str);
	}
	return (NULL);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;

	if (s)
	{
		if (!ft_strlen(s))
			return (ft_strnull());
		start = 0;
		end = 0;
		if (ft_start_end(s, &start, &end))
			return (ft_strsub(s, start, end - start + 1));
		else
			return (ft_strnull());
	}
	return (NULL);
}
