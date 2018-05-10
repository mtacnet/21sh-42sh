/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:26:45 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:26:47 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "expansion.h"

/*
**	Cette fonction recupere les valeurs des variables d'environnement et local,
**	a partir d'une string de recherche.
*/

static char		*ft_get_var(char *str, const char **env, const char **local)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_memalloc(sizeof(char) * (ft_end_dollar(str) + 1))))
		sh_error_exit(1, "in ft_get_var function");
	if (ft_isdigit(str[i]))
		ret[i] = str[i];
	else if (ft_isalpha_und(str[i]))
	{
		ret[i] = str[i];
		i++;
		while (ft_isalpha_und(str[i]) || ft_isdigit(str[i]))
		{
			ret[i] = str[i];
			i++;
		}
	}
	tmp = getenvloc(ret, (const char **)local, (const char **)env);
	ft_memdel((void **)&ret);
	return (tmp);
}

/*
**	Cette fonction renvoie la longueur de la string finale pour pouvoir malloc.
*/

static int		ft_malloc_dollar(char *str, const char **env,
									const char **local, int tild)
{
	char	*cmd;
	int		len;
	int		i;

	i = 0;
	len = 0;
	cmd = NULL;
	while (str[i])
	{
		if ((str[i] == '$' && ft_aft_dol(str + i + 1)) || tild_k(str, i, tild))
		{
			if (ft_isalpha_und(str[i + 1]) || ft_isdigit(str[i + 1]))
				cmd = ft_get_var(str + i + 1, env, local);
			else if (str[i + 1] == '?')
				cmd = getenvloc("?", local, env);
			else if (tild_k(str, i, tild))
				cmd = getenvloc("HOME", local, env);
			if (cmd)
				len += ft_strlen(cmd);
			i += ft_end_dollar(str + i + 1) + 1;
		}
		else
			i += (++len ? 1 : 0);
	}
	return (len + 1);
}

/*
**	Cette fonction ecrit sur la string malloc, qu'elle renvoie.
*/

static char		*ft_write_dollar(char *dest, char *str, const char **local,\
																	int tild)
{
	const char	**env;
	char		*cmd;
	int			i;
	int			j;

	i = 0;
	j = 0;
	env = (const char **)*(get_env(NULL));
	while (str[i])
	{
		if ((str[i] == '$' && ft_aft_dol(str + i + 1)) || tild_k(str, i, tild))
		{
			if (ft_isalpha_und(str[i + 1]) || ft_isdigit(str[i + 1]))
				cmd = ft_get_var(str + i + 1, env, local);
			else if (str[i + 1] == '?' || tild_k(str, i, tild))
				cmd = getenvloc((str[i + 1] == 63 ? "?" : "HOME"), local, env);
			(cmd ? ft_strcpy(dest + j, cmd) : NULL);
			j += (cmd ? ft_strlen(cmd) : 0);
			i += ft_end_dollar(str + i + 1) + 1;
		}
		else
			dest[j++] = str[i++];
	}
	return (dest);
}

/*
**	Cette fonction est la fonction principale.
**	Son but est de changer tout les '$' suivit d'une string ou d'un chiffreo
**	ou d'un '?' par les valeurs contenu dans l'env et le local.
*/

int				ft_expand_dollar(char **cmd, const char **env,
									const char **local, int tild)
{
	char	*ret;
	int		len;

	if (!ft_strchr((*cmd), '$') && !ft_strchr((*cmd), '~'))
		return (0);
	if (!(len = ft_malloc_dollar(*cmd, env, local, tild)))
		return (-1);
	if (!(ret = ft_memalloc(sizeof(char) * len)))
		sh_error_exit(1, "in ft_expand_dollar function");
	if (!(ret = ft_write_dollar(ret, *cmd, local, tild)))
		return (-1);
	ft_strdel(cmd);
	(*cmd) = ret;
	return (0);
}
