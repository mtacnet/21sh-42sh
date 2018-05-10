NAME	= liberror.a

CC		= gcc

RM		= rm -rf

LIBFT_INC = includes/


CFLAGS	= -Wall -Wextra -Werror -I $(LIBFT_INC) -I includes/

SRC_PATH =	src/

SRC_FILE =	error.c

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
