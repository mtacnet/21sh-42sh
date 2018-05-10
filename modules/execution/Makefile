NAME	= libexec.a

CC		= gcc

RM		= rm -rf

LIBFT_INC = includes/


CFLAGS	= -Wall -Wextra -Werror -I $(LIBSUP_INC) -I $(LIBFT_INC) -I includes/ \
-I $(PARSER_INC) -I $(LIBSUP2_INC) -I $(ERROR_INC) -I $(ENV_INC) -I $(BUILT_INC) -I $(HIST_INC) -I $(HERE_INC)

SRC_PATH =	src/

SRC_FILE =	exec.c pre_exec.c split.c utils.c utils2.c utils3.c value_ret.c \
			get_fd.c redir.c exec_cmd.c exec_core.c utils4.c

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILE))

OBJS	= $(SRCS:.c=.o)

GREEN	= \033[32m
ROUGE	= \033[1;31m
RESET	= \033[0m
MAGEN	= \033[35m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(MAGEN)Création de la bibliothèque $(NAME)"
	@ar rc $(NAME) $(OBJS)
	@echo "Création de l'index pour $(NAME)$(RESET)"
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "$(ROUGE)Suppression des fichiers objets de $(NAME)$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(ROUGE)Suppression de la bibliothèque $(NAME)$(RESET)"
	@$(RM) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
