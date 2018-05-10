/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:23:03 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:23:04 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_word(const char *s, char c)
{
	int	i;
	int	cmp;
	int	word;

	i = 0;
	cmp = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !word)
		{
			cmp++;
			word = 1;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (cmp);
}

/*
** Alloue et retourne un tableau de chaînes de caractères “fraîches” (toutes
** terminées par un ’\0’, le tableau également donc) résultant de la découpe
** de 'str' selon le caractère 'c'.
** Si l’allocation échoue, la fonction retourne NULL.
*/

static char			**split(char **new, size_t size, const char *str,
										char c)
{
	char	*begin;
	char	*end;
	size_t	i;

	i = 0;
	begin = (char*)str;
	end = NULL;
	while (begin && i < size)
	{
		if ((end = ft_strchr(begin, c)) && end > begin)
			new[i++] = ft_strsub(begin, 0, end - begin);
		else if (end > begin || !end)
			new[i++] = ft_strdup(begin);
		begin = (end ? end + 1 : end);
	}
	return (new);
}

char				**ft_strsplit(const char *str, char c)
{
	char	**new;
	size_t	size;

	new = NULL;
	if (str)
	{
		size = ft_count_word(str, c);
		if (!(new = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		{
			ft_putendl_fd("Erreur d'allocation", 2);
			return (NULL);
		}
		new = split(new, size, str, c);
	}
	return (new);
}
