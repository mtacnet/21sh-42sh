/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:46 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:50 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexec.h"

char	**get_cut_path(const char **env)
{
	if (ft_getenv("PATH", env))
		return (ft_strsplit(ft_getenv("PATH", env), ':'));
	else
		return (ft_strsplit(get_path(NULL), ':'));
}

char	*check_valid_path(char **path_tab, char *cmd)
{
	char	*tmp3;
	char	*tmp2;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	tmp2 = "/";
	tmp3 = NULL;
	if (path_tab)
	{
		while (path_tab[i] && path_tab[i][0] != '\0')
		{
			tmp3 = ft_strjoin(path_tab[i], tmp2);
			tmp = ft_strjoin(tmp3, cmd);
			ft_strdel(&tmp3);
			if (access(tmp, X_OK) == 0)
				return (tmp);
			ft_strdel(&tmp);
			tmp = NULL;
			i++;
		}
	}
	return (NULL);
}

int		return_free_exec(t_exec **exe)
{
	freelst_exec(exe);
	exe = NULL;
	return (-1);
}

int		catch_status_ret(pid_t child, int nohang, t_exec **exe, t_exec **sub)
{
	int		status;

	status = 0;
	if ((nohang && !is_no_redir(exe, 1)) || (sub && is_no_redir(sub, 0)))
		waitpid(child, &status, WNOHANG);
	else
		waitpid(child, &status, WUNTRACED);
	if (WIFEXITED(status))
	{
		set_value_ret(WEXITSTATUS(status));
		return (WEXITSTATUS(status));
	}
	if (WIFSIGNALED(status))
	{
		set_value_ret(128 + WTERMSIG(status));
		return (128 + WTERMSIG(status));
	}
	return (0);
}

int		open_file2(t_exec *file, t_exec *act)
{
	int		ret;

	ret = 0;
	if (file->token->token_id == OP_FILE_ARG &&
			act->token->token_id == OP_REDIR_GREAT)
	{
		ret = open(file->token->token, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR |
						S_IRGRP | S_IWGRP | S_IWUSR);
		if (ret == -1)
			return (sh_error_int(7, file->token->token));
	}
	else if (file->token->token_id == OP_FILE_ARG &&
			act->token->token_id == OP_REDIR_DGREAT)
	{
		ret = open(file->token->token, O_APPEND | O_RDWR | O_CREAT, S_IRUSR |
						S_IRGRP | S_IWGRP | S_IWUSR);
		if (ret == -1)
			return (sh_error_int(7, file->token->token));
	}
	return (ret);
}
