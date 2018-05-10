/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:29:52 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:29:54 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int				free_clear_env(char ***env, char ***previous_env)
{
	if (*env && ft_getenv("PATH", (const char **)*previous_env))
		get_path(ft_getenv("PATH", (const char **)*previous_env));
	if (*env)
		ag_strdeldouble(env);
	if (!(*env = (char **)ft_memalloc(sizeof(char *))))
		sh_error_exit(1, "in free_clear_env function");
	return (0);
}

int				builtin_env1(char **av, char **env_cpy)
{
	char	*line;
	int		ret;

	if (check_builtins(av[0]))
	{
		ft_putstr_fd("ERROR: no such file or directory: ", 2);
		ft_putendl_fd(av[0], 2);
		return (-1);
	}
	line = concat_args(av);
	ret = pre_exec(line, &env_cpy, 0);
	if (ret == 1 || ret == -1)
	{
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (0);
}

char			**dup_env(char ***env)
{
	char	**ret;

	ret = NULL;
	if (!ag_strlendouble(*env))
	{
		if (free_clear_env(&ret, NULL) == -1)
			return (NULL);
	}
	else if (!(ret = dupenv((const char **)*env, ag_strlendouble(*env))))
		return ((char**)sh_error_exit(1, "in dup_env function"));
	return (ret);
}

static int		sort_opt_env(int *i, char ***env_cpy, char ***env, char **av)
{
	while (av && av[*i] && (ft_strequ(av[*i], "-u") || ft_strequ(av[*i], "-i")))
	{
		if (ft_strequ(av[*i], "-i"))
			if (free_clear_env(env_cpy, env) == -1)
				return (-1);
		if (ft_strequ(av[*i], "-u"))
		{
			*i += 1;
			ft_unsetenv(av[*i], env_cpy);
		}
		*i += 1;
	}
	return (0);
}

int				builtin_env(char **av, char ***env)
{
	int		i;
	char	**env_cpy;

	i = 0;
	if (!(env_cpy = dup_env(env)))
		return (-1);
	if (sort_opt_env(&i, &env_cpy, env, av) == -1)
		return (-1);
	while (av && av[i] && ft_strchr(av[i], '='))
		if (ft_setenv(av[i++], &env_cpy) == -1)
			return (-1);
	if (!av || !av[i] || (ft_strequ(av[i], "env") && !av[i + 1]))
	{
		set_value_ret(0);
		print_env((const char **)env_cpy);
	}
	else if (builtin_env1(&av[i], env_cpy) == -1)
		return (-1);
	if (env_cpy)
		ag_strdeldouble(&env_cpy);
	return (0);
}
