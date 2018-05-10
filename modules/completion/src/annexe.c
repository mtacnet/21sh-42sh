/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:31:33 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:31:35 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
**	\brief	Insertion de backslash avant les espaces
**
**	\param	command	- commande à modifier
**
**	\return **chaîne** modifiée ou **NULL** en cas d'erreur
*/

char	*insert_backslash(char *command)
{
	int		i;
	int		b;
	int		len;

	if (command)
	{
		i = -1;
		b = 0;
		while (command[++i])
			if (command[i] == ' ')
				b++;
		len = ft_strlen(command);
		i = -1;
		if (b && (command = ag_memrealloc(command, len, len + b + 1)))
			while (command[++i])
				if (command[i] == ' ')
				{
					ft_memmove(&command[i + 1], &command[i], len + b - i);
					command[i++] = '\\';
				}
		if (b && !command)
			completion_error();
	}
	return (command);
}

/*
**	\brief	Teste si le caractère peut être un opérateur shell
**
**	\param	c	- caractère à comparer
**
**	\return	**1** si le caractère peut être une opérateur shell
**			ou **0** sinon.
*/

int		is_shellop(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '>' || c == '<')
		return (1);
	return (0);
}

/*
**	\brief	Message en cas d'erreur d'allocation
*/

void	completion_error(void)
{
	ft_putendl_fd("", 2);
	sh_error_exit(1, "in function completion");
}

/*
**	\brief	Libération de mémoire
*/

void	completion_del(void *content, size_t content_size)
{
	if (content)
		ft_memdel(&content);
	if (content_size)
		NULL;
}
