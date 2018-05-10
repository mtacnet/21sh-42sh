/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberror.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:33:44 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:33:45 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBERROR_H
# define LIBERROR_H

# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

void				*sh_error(int val, char *fct);
int					sh_error_int(int val, char *fct);
void				*sh_error_exit(int val, char *fct);

#endif
