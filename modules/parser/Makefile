NAME	= libparser.a

CC		= gcc

RM		= rm -rf

LIBFT_INC = includes/


CFLAGS	= -Wall -Wextra -Werror -I $(LIBFT_INC) -I includes/ -I $(LIBSUP2_INC) \
-I $(ERROR_INC)

SRC_PATH =	src/

SRC_FILE =	ast.c ast_pass.c check_arg.c format.c ft_cpy_lst.c ft_init_list.c \
ft_list.c ft_list2.c ft_view_list.c lexer.c list_tab.c parser.c precision.c \
utils.c utils2.c verif.c parser_err.c

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
