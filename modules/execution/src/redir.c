/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:34:34 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:34:35 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexec.h"

t_exec		*remaining_redir(t_exec **exe, int what, int i)
{
	t_exec	*tmp;

	tmp = *exe;
	if (i)
		tmp = tmp->next;
	while (tmp)
	{
		if (what != 1 && tmp->token && tmp->token->token_id &&
			(tmp->token->token_id == OP_REDIR_GREAT ||
				tmp->token->token_id == OP_REDIR_DGREAT ||
				tmp->token->token_id == OP_AGREG_GREAT))
			return (tmp);
		else if (what && tmp->token && tmp->token->token_id &&
			(tmp->token->token_id == OP_REDIR_LESS ||
				tmp->token->token_id == OP_HEREDOC ||
				tmp->token->token_id == OP_AGREG_LESS))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			left_redir(char *file, int phd)
{
	int		fd;
	char	*buf;
	int		ret;

	ret = 0;
	buf = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &buf)) == 1)
	{
		ft_putendl_fd(buf, phd);
		if (buf)
			ft_strdel(&buf);
	}
	return (ret);
}

int			left_here(t_exec **exe, int phd[2])
{
	t_exec	*tmp;
	t_exec	*prev;
	int		i;

	i = 0;
	tmp = *exe;
	close(phd[0]);
	while ((tmp = remaining_redir(&tmp, 1, i)))
	{
		prev = tmp;
		i++;
	}
	if (prev)
	{
		if (prev->token->token_id == OP_HEREDOC)
			ft_putstr_fd(prev->next->token->token, phd[1]);
		else if (prev->token->token_id == OP_REDIR_LESS)
		{
			if (left_redir(prev->next->token->token, phd[1]))
				return (-1);
		}
	}
	close(phd[1]);
	return (0);
}

int			process_redir(t_exec **exe)
{
	int		fd_out;
	int		fd_in;
	t_exec	*tmp;
	int		i;

	i = 0;
	tmp = *exe;
	while ((tmp = remaining_redir(&tmp, 0, i)))
	{
		if ((fd_out = get_fd(&tmp, 2)) == -1)
			return (-1);
		if ((fd_in = get_fd(&tmp, 1)) == -1)
			return (-1);
		if (dup2(fd_out, fd_in) == -1)
			return (sh_error_int(22, tmp->next->token->token));
		if (fd_out != 1)
			close(fd_out);
		i++;
	}
	return (0);
}
