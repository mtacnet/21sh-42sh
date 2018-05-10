/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:29:49 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:29:50 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		wrong_char(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != 'e' && str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

t_opt	get_flags(char **args, int *where)
{
	int		i;
	int		j;
	t_opt	ret;

	ret.n = 0;
	ret.e = 0;
	i = 0;
	while (args && args[i] && args[i][0] == '-')
	{
		j = 1;
		if (wrong_char(&args[i][1]))
			break ;
		while (args[i][j] && (args[i][j] == 'n' || args[i][j] == 'e'))
		{
			if (args[i][j] == 'n')
				ret.n = 1;
			if (args[i][j] == 'e')
				ret.e = 1;
			j++;
		}
		i++;
	}
	*where = i;
	return (ret);
}

int		get_char(char *str, int *len, int *c)
{
	*len = 1;
	if (str[0] == 'b')
		return ('\b');
	else if (str[0] == 'f')
		return ('\f');
	else if (str[0] == 'n')
		return ('\n');
	else if (str[0] == 'r')
		return ('\r');
	else if (str[0] == 't')
		return ('\t');
	else if (str[0] == 'v')
		return ('\v');
	else if (str[0] == '\\')
		return ('\\');
	else if (str[0] == '0')
		return (what_char_is_it(&str[1], len));
	else if (str[0] == 'c')
	{
		*c = 1;
		return (-2);
	}
	else
		*len = 0;
	return (0);
}

char	*translate(char *ret, int *c_enabled, int i, int len)
{
	int		c;
	char	*tmp;
	char	*tmp2;

	while (ret[++i])
		if (ret[i] == '\\')
		{
			c = get_char(&ret[i + 1], &len, c_enabled);
			tmp = ft_strsub(ret, 0, i);
			if (c >= 0)
				tmp2 = ft_strsub(ret, i + len + 1,
					ft_strlen(ret) - (i + len + 1));
			else
				tmp2 = ft_strdup("\0");
			if (ret)
				ft_strdel(&ret);
			ret = backslash_it(tmp, tmp2, (char)c);
			if (tmp)
				ft_strdel(&tmp);
			if (tmp2)
				ft_strdel(&tmp2);
		}
	return (ret);
}

int		builtin_echo(char **args)
{
	t_opt	opt;
	int		i;
	char	*to_print;
	int		c_enabled;

	c_enabled = 0;
	i = 0;
	opt = get_flags(args, &i);
	to_print = concat_args(&args[i]);
	if (opt.e && to_print)
		to_print = translate(to_print, &c_enabled, -1, 0);
	if (to_print)
		ft_putstr(to_print);
	if (!(c_enabled || opt.n))
		ft_putchar('\n');
	ft_strdel(&to_print);
	return (0);
}
