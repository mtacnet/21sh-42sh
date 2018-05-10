/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_exclam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:26:50 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:26:52 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "expansion.h"

/*
**	Les deux fonction suivantes donnent pour les cmd de l'hist pour:
**	- le cas des digits.
**	- le cas des alphas.
*/

static char		*ft_digit_node(t_lstag *hist, int nb)
{
	int		move;
	int		lst_len;

	lst_len = ag_lstcountelem(hist);
	if (nb > lst_len || nb < -lst_len)
		return (NULL);
	if (nb > 0)
		move = lst_len - nb;
	else if (nb < 0)
		move = (nb + 1) * -1;
	else
		return (NULL);
	while (move)
	{
		hist = hist->next;
		move--;
	}
	return (ft_strdup(hist->content));
}

static char		*ft_alpha_node(t_lstag *hist, char *str)
{
	t_lstag		*find;
	char		*search;
	int			i;

	i = 0;
	while (ft_isalpha(str[i]))
		i++;
	if (!(search = ft_memalloc(sizeof(char) * (i + 1))))
		sh_error_exit(1, "in ft_alpha_node function");
	i = 0;
	while (ft_isalpha(str[i]))
	{
		search[i] = str[i];
		i++;
	}
	if (!(find = search_history_begin(hist, search)))
	{
		ft_strdel(&search);
		return (NULL);
	}
	search ? ft_strdel(&search) : NULL;
	if (find->content)
		search = ft_strdup(find->content);
	find ? ag_lstdel(&find, del_l) : NULL;
	return (search);
}

/*
**	Les deux fonctions suivantes font chacune:
**	- Donne la longueur de la string finale.
**	- Ecrit la string finale.
*/

static int		ft_malloc_exclam(char *str, t_lstag *hist)
{
	char		*cmd;
	int			len;
	int			i;

	i = 0;
	len = 0;
	cmd = NULL;
	while (str[i])
		if (str[i] == '!' && ft_after_exclam(str + i + 1))
		{
			if (ft_isdigit((str[i + 1] == '-' ? str[i + 2] : str[i + 1])))
				cmd = ft_digit_node(hist, ft_atoi(str + i + 1));
			else if (ft_isalpha(str[i + 1]))
				cmd = ft_alpha_node(hist, (str + i + 1));
			else if (str[i + 1] == '!')
				cmd = ft_digit_node(hist, -1);
			if (!cmd)
				return (ft_enf((str + i + 1), 0));
			len += ft_strlen(cmd);
			cmd ? ft_strdel(&cmd) : NULL;
			i += ft_end_exclam(str + i + 1);
		}
		else
			i += (++len ? 1 : 0);
	return (len + 1);
}

static char		*ft_write_exclam(char *dest, char *str, t_lstag *hist)
{
	char		*cmd;
	int			i;
	int			j;

	i = 0;
	j = 0;
	cmd = NULL;
	while (str[i])
		if (str[i] == '!' && ft_after_exclam(str + i + 1))
		{
			if (ft_isdigit((str[i + 1] == '-' ? str[i + 2] : str[i + 1])))
				cmd = ft_digit_node(hist, ft_atoi(str + i + 1));
			else if (ft_isalpha(str[i + 1]))
				cmd = ft_alpha_node(hist, (str + i + 1));
			else if (str[i + 1] == '!')
				cmd = ft_digit_node(hist, -1);
			if (!cmd)
				return ((ft_enf((str + i + 1), 0) ? NULL : NULL));
			ft_strcpy(dest + j, cmd);
			((j += ft_strlen(cmd)) ? ft_strdel(&cmd) : NULL);
			i += ft_end_exclam(str + i + 1);
		}
		else
			dest[j++] = str[i++];
	return (dest);
}

/*
**	C'est la fonction principale du fichier.
**	Elle recoit un pointer sur la ligne de cmd et sur l'historique.
**	---------------------------------------------------
**	L'objectif est de remplacer tout les '!' suivient d'un digit (pos/neg)
**	ou d'un alpha (un '!' suivant un autre '!' est remplace par "!-1"
**	et compte comme un digit) par la cmd de l'historique qui correspond.
**	(les digits neg commence par les derniere commande et inversement pour
**	les positifs).
*/

int				ft_expand_exclam(char **cmd, t_lstag *hist)
{
	char		*ret;
	int			len;

	if (!ft_strchr(*cmd, '!'))
		return (0);
	if (!(len = ft_malloc_exclam(*cmd, hist)))
		return (-1);
	if (!(ret = ft_memalloc(sizeof(char) * len)))
		sh_error_exit(1, "in ft_expand_exclam function");
	if (!(ret = ft_write_exclam(ret, (*cmd), hist)))
		return (-1);
	ft_strdel(cmd);
	(*cmd) = ret;
	ft_putendl(ret);
	return (0);
}
