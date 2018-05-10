/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:45:59 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:47:41 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_INPUT_H
# define LINE_INPUT_H

# include "libft.h"
# include "libag.h"
# include "environment.h"
# include "completion.h"
# include "liberror.h"
# include "heredoc.h"
# include <stdlib.h>
# include <unistd.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

/*
**	\brief	Taille d'allocation
**
**	L'allocation de la chaîne nécessaire à contenir la commande se fait de
**	4096 en 4096
*/

# define INPUT_BUF_SIZE 4096

/*
**	\brief	Allocation maximale pour la ligne de commande
*/

# define MAX_ALLOC 262144

/*
**	\brief	Informations sur la ligne
*/

/*
**	size		Taille de l'allocation
**	len			Taille de la chaîne
**	cursor_i	Index du curseur dans la chaîne (>= 0)
**	cursor_x	Colonne du curseur sur la ligne
**	cursor_y	Ligne du curseur sur la ligne de commande
**	prompt		Longueur du prompt
**	nb_line		Nombre de ligne nécessaires à l'affichage
**	win_col		Nombre de colonnes de la fenêtre
**	cursor_s	Indice du début/de la fin de la sélection par rapport au curseur
**	term		Booléen indiquant si l'environnement a pu être récupéré ou non
*/

typedef struct	s_line
{
	size_t	size;
	size_t	len;
	size_t	cursor_i;
	size_t	cursor_x;
	size_t	cursor_y;
	size_t	prompt;
	size_t	nb_line;
	size_t	win_col;
	int		cursor_s;
	int		term;
}				t_line;

/*
**	heredoc.c
*/

int				is_in_heredoc(int i);
char			*redoc_delimiter(char *str);

/*
**	input.c
*/

t_line			init_line_info(size_t size, char *prompt);
char			*line_input(char *prompt, t_lstag *history, char **environ,
							char **builtin);

/*
**	completion.c
*/

int				complete_line(char **line, t_line *info);

/*
**	cursor_motion.c
*/

int				move_cursor_on_line(char m, t_line *line_info);
int				move_ctrl_arrow(char m, char *line, t_line *line_info);

/*
**	edit.c
*/

int				insert_char(char **line, char c, t_line *line_info);
int				delete_char(char **line, char t, t_line *line_info);
int				swap_char(char **line, t_line *line_info);

/*
**	history.c
*/

void			delete_save(void);
char			**get_save(char **line);
int				manage_history(char **line, char m, t_line *line_info,
															t_lstag *history);

/*
**	key.c
*/

int				check_key(char **line, char buf[], t_line *line_info,
															t_lstag *history);

/*
**	path.c
*/

int				first_word(const char *line, int pos);
char			**find_path(char *line, char **path, char **word, t_line *info);
char			*verif_path(char *path);

/*
**	print.c
*/

void			print_line(char *line, t_line line_info, char *prompt);

/*
**	read.c
*/

void			input(char **line, t_line *line_info, char *prompt,
															t_lstag *history);

/*
**	selection.c
*/

int				selection(char n, char m, char *line, t_line *line_info);

/*
**	selection_edit.c
*/

char			*get_clipboard(char *content, int del);
int				paste_selection(char **line, t_line *line_info);
int				copy_cut_selection(char **line, int cut, t_line *line_info);
int				insert_char_selection(char **line, char c, t_line *line_info);
int				delete_selection(char **line, t_line *line_info);

/*
**	sigleton.c
*/

t_line			*get_line_info(t_line *info);
char			**get_environ(char **env);
char			**get_builtin(char **builtin);
char			**get_line(char **line);
char			*get_prompt(char *prompt);

/*
**	signal.c
*/

void			launch_signal(void);

/*
**	update.c
*/

int				nb_line(size_t len, size_t col);
void			update_info(t_line *line_i, const char *line);
void			replace_cursor(t_line line_info);

/*
**	debug.c
*/

void			debug_struct(t_line line_info, char *msg);
void			debug_read(char buf[]);

#endif
