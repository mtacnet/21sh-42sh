# Nom
NAME = libsup.a
PROJECT = libsup

# Options de compilation
CC = @gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I includes/ -I $(LIBFT_INC)

# Headers
INC_FILE = libag.h get_next_line.h
INC = $(addprefix includes/, $(INC_FILE))

# Sources
SRC_CNV = ag_atoi_base.c ag_itoa_base.c
SRC_IS	= ag_isnumber.c ag_isspace.c ag_iscase.c
SRC_LST = ag_lstadd.c ag_lstcountelem.c ag_lstdel.c ag_lstdelone.c ag_lstiter.c ag_lstmapif.c ag_lstnew.c ag_lsthead.c ag_lsttail.c ft_lstaddalpha.c ft_lstcount.c
SRC_MTH = ag_factorial.c ag_sqrt.c ag_pow.c
SRC_MEM = ag_memrealloc.c ag_strdeldouble.c
SRC_OTH = get_next_line.c ag_swap.c fill_tab.c ag_nbrlen.c
SRC_PAT = isdir.c
SRC_PUT = ag_putchar.c ag_putchar_fd.c ag_putchoice.c ag_putnbr.c ag_putnbr_fd.c ag_putnstr.c ag_putnstr_fd.c ag_putstrcase.c ag_putstrs.c ag_putstrs_fd.c
SRC_STR = ag_strequ.c ag_strfreejoin.c ag_strlendouble.c ag_strnrchr.c ag_strtocase.c count_word.c
SRC = $(addprefix src/conversion/, $(SRC_CNV))\
	$(addprefix src/is/, $(SRC_IS))\
	$(addprefix src/list/, $(SRC_LST))\
	$(addprefix src/math/, $(SRC_MTH))\
	$(addprefix src/memory/, $(SRC_MEM))\
	$(addprefix src/others/, $(SRC_OTH))\
	$(addprefix src/path/, $(SRC_PAT))\
	$(addprefix src/put/, $(SRC_PUT))\
	$(addprefix src/string/, $(SRC_STR))

# Objets
OBJ = $(SRC:.c=.o)

# Règles
all: $(NAME)

$(NAME) : Makefile $(LIBFT_INC) $(OBJ)
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
