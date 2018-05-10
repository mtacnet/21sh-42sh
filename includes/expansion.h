/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:26:18 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:50:43 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "libft.h"
# include "libag.h"
# include "libmt.h"

/*
**	line.c
*/

void		del_l(void *content, size_t content_size);

/*
**	ft_expand_index.c
*/

int			ft_after_exclam(char *str);
int			ft_enf(char *cmd, int val);
int			ft_end_exclam(char *str);
int			ft_end_dollar(char *str);

/*
**	ft_expand_is.c
*/

int			ft_isredir(int c);
int			ft_isalpha_und(int c);
int			ft_aft_dol(char *str);
int			check_before(char *str, int index);
int			tild_k(char *str, int i, int tild);

/*
**	ft_expand_dollar.c ft_expand_exclam.c
*/

int			ft_expand_exclam(char **cmd, t_lstag *hist);
int			ft_expand_dollar(char **cmd, const char **env, const char **local,\
			int check_tild);

#endif
