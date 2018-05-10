/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:30:01 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:30:02 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	history_error(int i, char l, const char *args)
{
	ft_putstr_fd("history: ", 2);
	if (i == 1)
	{
		ft_putstr_fd("invalid option : ", 2);
		ag_putcharl_fd(l, 2);
	}
	else if (i == 2)
	{
		ft_putstr_fd(args, 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else if (i == 3)
		ft_putendl_fd("position out of range", 2);
	return (-1);
}

static int	delete_line(t_lstag **history, int nb)
{
	t_lstag	*tmp;
	t_lstag	*prev;
	t_lstag	*next;

	if (nb < 1 || nb > ag_lstcountelem(*history))
		return (history_error(3, 0, NULL));
	tmp = ag_lsttail(*history);
	while (tmp && --nb)
		tmp = tmp->prev;
	if (tmp)
	{
		if ((prev = tmp->prev))
			prev->next = tmp->next;
		if ((next = tmp->next))
			next->prev = tmp->prev;
		tmp->prev = NULL;
		tmp->next = NULL;
		delete_history_list(&tmp);
		if (prev)
			*history = ag_lsthead(prev);
		else
			*history = ag_lsthead(next);
	}
	return (0);
}

/*
**	opt 0 = a, 1 = c, 2 = d, 3 = e, 4 = n, 5 = r, 6 = s, 7 = w
*/

static int	get_opt2(char *args, int i, char *opt, t_lstag **history)
{
	char	l;

	while ((l = args[i++]))
		if (l == 'c')
			delete_history_list(history);
		else if (opt)
		{
			if (l == 'a')
				write_history(opt, ag_lsttail(*history));
			else if (l == 'd')
				if (!ag_isnumber(opt))
					return (history_error(2, 0, "-d"));
				else
					delete_line(history, ft_atoi(opt));
			else if (l == 'e')
				delete_history_file_content(opt);
			else if (l == 'r')
				*history = read_history(opt, *history);
			else if (l == 's')
				*history = add_history_lst(*history, opt);
			else if (opt)
				return (history_error(1, l, NULL));
			opt = NULL;
		}
	return (0);
}

static int	get_opt(char *args, char *opt, t_lstag **history)
{
	int		i;

	i = 0;
	if (args[i++] == '-')
		return (get_opt2(args, i, opt, history));
	else if (!ag_isnumber(args))
		return (history_error(2, 0, args));
	else
		print_history(*history, ft_atoi(args));
	return (0);
}

/*
**	\brief	Builtin pour l'historique
**
**	Options :
**
**	- a	[fichier]	: écrit l'historique dans le fichier
**	- c				: efface la liste
**	- d	valeur		: efface la **d**ième entrée de la liste
**	- e	[fichier]	: supprime le contenu du fichier de l'historique
**	- r	[fichier]	: ajoute le contenu du fichier dans la liste
**	- s	[fichier]	: ajoute les arguments à la liste comme une commande
**
**	Si le _fichier_ n'est pas renseigné avec une option prenant ce paramètre,
**	la fonction utilisera la variable HISTFILE de l'environnement ou
**	des locales pour le trouver.
**	Si plusieurs options prenant en paramètre une valeur/un fichier
**	sont utilisées en même temps, seule la première sera effectuée.
**	Par exemple, seules `c` et `r` seront effectuées dans cette commande :
**
**	$> history -rca ~/.history
**
**	\paraml	args	- paramètre(s) du builtin
**	\param	history	- pointeur sur la tête de liste de l'historique
**	\param	env		- variables d'environnement
**	\param	local	- variables locales
**
**	\return	**1** en cas d'erreur ou **0** sinon
*/

int			builtin_history(char **args, t_lstag **history,\
		const char **env, const char **local)
{
	int		i;
	int		ret;
	char	*opt;

	if (args && history)
	{
		i = 0;
		ret = 0;
		if (!args[i])
			print_history(*history, -1);
		else
			while (args[i] && !ret)
			{
				opt = NULL;
				if (args[i + 1] && args[i + 1][0] != '-')
					opt = args[i + 1];
				else if (!(opt = ft_getenv("HISTFILE", env)))
					opt = ft_getenv("HISTFILE", local);
				ret = get_opt(args[i], opt, history);
				if (args[++i] && args[i][0] != '-')
					i++;
			}
		return (ret);
	}
	return (-1);
}
