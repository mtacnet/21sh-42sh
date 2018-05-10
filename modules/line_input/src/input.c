/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:46:38 by mtacnet           #+#    #+#             */
/*   Updated: 2018/05/03 22:46:41 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_input.h"

/*
**	\brief	Initialisation de la structure `t_line`
**
**	La fonction initalise les champs de la structure `t_line`.
**
**	\param	size	- taille de l'allocation initiale
**	\param	prompt	- chaîne représentant le prompt
**
**	\return	`structure t_line` initialisée
*/

t_line		init_line_info(size_t size, char *prompt)
{
	t_line	line_info;

	line_info.size = size;
	line_info.prompt = ft_strlen(prompt) + 1;
	line_info.len = 0;
	line_info.cursor_i = 0;
	line_info.cursor_x = line_info.prompt;
	line_info.cursor_y = 1;
	line_info.cursor_s = -1;
	line_info.nb_line = 0;
	return (line_info);
}

/*
**	Modification du comportement du terminal
*/

static void	set_term(void)
{
	struct termios	new;

	tcgetattr(0, &new);
	new.c_lflag &= ~(ICANON);
	new.c_lflag &= ~(ECHO);
	new.c_cc[VTIME] = 0;
	new.c_cc[VMIN] = 1;
	tcsetattr(0, TCSADRAIN, &new);
}

/*
**	Rétablissement du comportement par défaut du terminal
*/

static void	reset_term(struct termios save)
{
	tcsetattr(0, 0, &save);
}

static void	quit_line_input(struct termios save)
{
	delete_save();
	manage_history(NULL, 0, NULL, NULL);
	reset_term(save);
	if (!is_in_heredoc(-1))
		signal(SIGINT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
}

/*
**	\brief	Gestion de la ligne de commande
**
**	La fonction s'occupe de la gestion de la ligne de commande. Elle permet de
**	se déplacer dans celle-ci avec les flèches, de l'éditer et d'accéder
**	aux autres lignes de l'historique s'il est disponible.
**	Lorsque l'utilisateur appuie sur _entrée_, la fonction renvoie la chaîne
**	contenant les commandes.
**
**	La fonction intercepte les signaux `SIGINT` et `SIGTSTP` et les rétablit à
**	leurs comportements par défaut avant de retourner la commande.
**	Si la fonction appelante a également besoin d'intercepter ces signaux,
**	elle devra les rétablir après l'appel à _line_input_.
**
**	\param	prompt			- prompt à afficher
**	\param	history			- liste pour historique, peut être `NULL` si
**							celui-ci n'existe pas
**	\param	environ			- environnment (ne peut être `NULL`)
**	\param	builtin			- tableau contenant le nom des builtins
**
**	\return	*commande* tappée par l'utilisateur ou `NULL` en cas d'erreur
*/

char		*line_input(char *prompt, t_lstag *history, char **environ,
						char **builtin)
{
	char			*line;
	t_line			line_info;
	struct termios	save;

	if ((line = (char*)ft_memalloc(sizeof(char) * (INPUT_BUF_SIZE + 1))))
	{
		launch_signal();
		ag_putstrs(prompt);
		line_info = init_line_info(INPUT_BUF_SIZE, prompt);
		if (environ && !(line_info.term = tgetent(NULL,\
					ft_getenv("TERM", (const char**)environ)) <= 0 ? 0 : 1))
			tgetent(NULL, "xterm");
		get_environ(environ);
		get_builtin(builtin);
		get_line_info(&line_info);
		get_line(&line);
		get_prompt(prompt);
		tcgetattr(0, &save);
		set_term();
		input(&line, &line_info, prompt, history);
		quit_line_input(save);
	}
	else
		sh_error(1, "in function line_input");
	return (line);
}
