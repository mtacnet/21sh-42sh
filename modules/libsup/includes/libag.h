/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libag.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:39:03 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:39:11 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBAG_H
# define LIBAG_H

# include "libft.h"
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>

/*
**	conversions
*/

int				ag_atoi_base(const char *str, int base);
char			*ag_itoa_base(unsigned long nb, int base);

/*
**	is
*/

int				ag_isnumber(const char *str);
int				ag_isspace(int c);
int				ag_islowercase(char c);
int				ag_isuppercase(char c);

/*
**	list
*/

/*
** \brief	Structure pour les listes
**
** \param	content			- Variable pour le stockage d'une valeur
** \param	content_size	- Taille de la variable
** \param	prev			- Pointeur sur le maillon précédent
** \param	next			- Pointeur sur le maillon suivant
*/

typedef struct	s_lstag
{
	void			*content;
	size_t			content_size;
	struct s_lstag	*prev;
	struct s_lstag	*next;
}				t_lstag;

void			ag_lstadd(t_lstag **alst, t_lstag *new);
void			ag_lstaddtail(t_lstag **alst, t_lstag *new);
t_lstag			*ag_lstnew(void const *content, size_t content_size);
void			ag_lstdelone(t_lstag **alst, void (*del)(void *, size_t));
void			ag_lstdel(t_lstag **alst, void (*del)(void *, size_t));
int				ag_lstcountelem(t_lstag *list);
void			ag_lstiter(t_lstag *lst, void (*f)(t_lstag *elem));
t_lstag			*ag_lsthead(t_lstag *list);
t_lstag			*ag_lsttail(t_lstag *list);
t_lstag			*ag_lstmapif(t_lstag *lst, int (*f)(t_lstag*),
											void (add)(t_lstag**, t_lstag*));

/*
**	fonctions pour la liste de la libft
*/

t_list			*ft_lstaddalpha(t_list **alst, t_list *new);
int				ft_lstany(t_list *list, int f(void *));
int				ft_lstcount(t_list *list);
int				ft_lstcount_all(t_list *lst, int f(void*));
int				ft_lstcount_if(t_list *list, int f(void*));

/*
**	math
*/

int				ag_factorial(int nb);
long long int	ag_pow(int nb, unsigned int pow);
int				ag_sqrt(int nb);

/*
**	memory
*/

void			ag_strdeldouble(char ***str);
void			*ag_memrealloc(void *old, size_t oldsize, size_t newsize);

/*
**	others
*/

void			ag_swap(int *a, int *b);
void			fill_tab(int tab[], unsigned int size, int value);
int				ag_nbrlen(long nb);

/*
**	path
*/

int				isdir(const char *path);

/*
**	put
*/

int				ag_putcharl(char c);
int				ag_putchars(char c);
int				ag_putxchar(char c, int x);
int				ag_putchars_fd(char c, int fd);
int				ag_putcharl_fd(char c, int fd);
int				ag_putnbrl(int n);
int				ag_putnbrs(int n);
int				ag_putnbrl_fd(int n, int fd);
int				ag_putnbrs_fd(int n, int fd);
int				ag_putstrs(char const *str);
int				ag_putstrs_fd(char const *str, int fd);
int				ag_putstrlower(const char *str);
int				ag_putstrupper(const char *str);

int				ag_putnstr(const char *str, unsigned int n);
int				ag_putnstrl(const char *str, unsigned int n);
int				ag_putnstrs(const char *str, unsigned int n);
int				ag_putnstr_fd(const char *str, unsigned int n, int fd);
int				ag_putnstrl_fd(const char *str, unsigned int n, int fd);
int				ag_putnstrs_fd(const char *str, unsigned int n, int fd);

int				ag_putchoice(const char **dstr);

/*
**	string
*/

int				ag_strequ(char const *s1, char const *s2);
int				ag_strnequ(char const *s1, char const *s2, size_t n);
int				ag_strlendouble(char **str);
char			*ag_strnrchr(const char *s, int c, int n);
char			*ag_strtolower(char *str);
char			*ag_strtoupper(char *str);
unsigned int	count_word(char *s, char c);
char			*ag_strfreejoin(char *s1, char *s2);

#endif
