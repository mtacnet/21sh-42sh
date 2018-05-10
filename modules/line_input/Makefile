# Nom
NAME = liblinput.a
PROJECT = line_input

# Options de compilation
CC = @gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I includes/ -I $(LIBFT_INC) -I $(LIBSUP_INC) -I $(ENV_INC) -I $(CMP_INC) -I $(HERE_INC) -I $(ERROR_INC)

# Headers
INC_FILE = line_input.h
INC = $(addprefix includes/, $(INC_FILE))

# Sources
SRC_FILE = completion.c cursor_motion.c edit.c heredoc.c history.c input.c key.c path.c print.c read.c selection.c selection_edit.c singleton.c signal.c update.c debug.c
SRC = $(addprefix src/, $(SRC_FILE))

# Objets
OBJ = $(SRC:.c=.o)

# Règles
all: $(NAME)

$(NAME) : Makefile $(LIBFT_INC) $(LIBAG_INC) $(CMP_INC) $(ENV_INC) $(ERROR_INC) $(OBJ)
	@echo "$(MAGEN)Création de la bibliothèque $(NAME)"
	@ar rc $(NAME) $(OBJ)
	@echo "Création de l'index pour $(NAME)$(RESET)"
	@ranlib $(NAME)

$(OBJ) : $(INC)

clean:
	@echo "$(ROUGEC)Suppression des fichiers objets de $(NAME)$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(ROUGEC)Suppression de la bibliothèque $(NAME)$(RESET)"
	@rm -f $(NAME)

re: fclean all

# Couleurs
RESET = \033[0m
BLANC = \033[37m
BLEU  = \033[34m
CYAN  = \033[36m
JAUNE = \033[33m
MAGEN = \033[35m
NOIR  = \033[30m
ROUGE = \033[31m
ROUGEC = \033[1;31m
VERT  = \033[32m

.PHONY: all clean fclean re doxygen cleandoxy
