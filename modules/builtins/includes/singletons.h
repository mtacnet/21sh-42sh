/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:28:56 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:28:58 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLETONS_H
# define SINGLETONS_H

char		***get_loc(char ***loc);
char		***get_env(char ***env);
char		*get_history_file(const char *file);
char		**get_shbuiltin(void);
void		sh_resetsignal(void);
t_exec		**get_exe(t_exec **exe);
t_tok		**get_tok(t_tok **tok);
void		get_term(int i);

#endif
