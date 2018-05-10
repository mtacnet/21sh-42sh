NAME =			libuiltins.a

SRCS =			builtin_cd.c \
				builtin_echo.c \
				builtin_env.c \
				builtin_exit.c \
				builtin_history.c\
				builtin_set.c \
				builtin_setenv.c \
				builtin_unset.c \
				builtin_unsetenv.c \
				tools.c \
				tools2.c \
				tools3.c \

SRCSD =			$(addprefix src/, $(SRCS))

CFLAGS =		-Wall -Wextra -Werror

CPPFLAGS = 		-I includes -I $(LIBFT_INC) -I $(LIBSUP_INC) -I $(ENV_INC) \
				-I $(HIST_INC) -I $(ERROR_INC) -I $(EXEC_INC)\
				-I $(PARSER_INC) -I $(LIBSUP2_INC) -I $(ERROR_INC) \
				-I $(SH_INC)

OBJS =			$(addprefix objs/, $(notdir $(SRCSD:.c=.o)))

GREEN= \033[32m
ROUGE= \033[1;31m
RESET= \033[0m
MAGEN= \033[35m

all:			$(NAME)

$(NAME):		Makefile objs $(OBJS)
	@echo "$(MAGEN)Création de la bibliothèque $(NAME)"
	@ar rc $(NAME) $(OBJS)
	@echo "Création de l'index pour $(NAME)$(RESET)"

objs/%.o:		src/%.c
	@gcc -o $@ -c $< $(CFLAGS) $(CPPFLAGS)

clean:
	@rm -rf objs
	@echo "$(ROUGE)Suppression des fichiers objets de $(NAME)$(RESET)"

objs:
	@mkdir objs

fclean:			clean
	@rm -rf $(NAME)
	@echo "$(ROUGE)Suppression de la bibliothèque $(NAME)$(RESET)"

re:				fclean all

.PHONY:			re fclean clean
