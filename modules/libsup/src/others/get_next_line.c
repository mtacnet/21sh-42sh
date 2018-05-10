/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:42:36 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:42:37 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoin_free(char *s1, char *s2, char flag)
{
	char	*out;

	out = ft_strjoin(s1, s2);
	if (flag == 'l' || flag == 'b')
		free(s1);
	if (flag == 'r' || flag == 'b')
		free(s2);
	return (out);
}

static int		fill_buffer(int fd, char **line, char **stock)
{
	char	*buff;
	char	*chr;
	int		ret;

	if (!(buff = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (!(chr = ft_strchr(buff, '\n')))
			*line = ft_strjoin_free(*line, buff, 'l');
		else
		{
			*chr++ = 0;
			if (stock[fd])
				free(stock[fd]);
			stock[fd] = ft_strdup(chr);
			*line = ft_strjoin_free(*line, buff, 'b');
			return (1);
		}
	}
	free(buff);
	if (ret < 0)
		return (-1);
	return (ft_strlen(*line) == 0 ? 0 : 1);
}

static int		extract_stock(int fd, char **line, char **stock)
{
	char	*chr;
	char	*temp;
	int		ret;

	chr = ft_strchr(stock[fd], '\n');
	temp = (chr ? ft_strdup(chr + 1) : NULL);
	if (!chr)
	{
		*line = ft_strjoin_free(*line, stock[fd], 'l');
		ft_memdel((void**)&(stock[fd]));
		ret = fill_buffer(fd, line, stock);
		return (ret);
	}
	else
	{
		*chr = 0;
		*line = ft_strjoin_free(*line, stock[fd], 'b');
		stock[fd] = ft_strdup(temp);
		free(temp);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stock[MAX_FD];
	int			ret;

	ret = 0;
	if (fd < 0 || line == NULL || fd >= MAX_FD)
		return (-1);
	*line = ft_strdup("");
	if (!stock[fd])
		ret = fill_buffer(fd, line, stock);
	else
		ret = extract_stock(fd, line, stock);
	if (ret <= 0)
	{
		ft_strdel(line);
		ft_memdel((void**)&(stock[fd]));
	}
	return (ret);
}
