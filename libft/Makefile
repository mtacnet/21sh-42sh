# Nom de sortie
NAME = libft.a

# Options de compilation
CC = @gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I$(INC_PATH)

# Headers
INC_PATH = includes/
INC_FILE = libft.h

# Fichiers sources
SRC_PATH = src/

##### Libft et bonus
CHAR_FILE = ft_tolower.c ft_toupper.c
CONV_FILE = ft_atoi.c ft_itoa.c 
IS_FILE = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
LIST_FILE = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c
MEM_FILE = ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_strdel.c ft_striter.c ft_striteri.c ft_strnew.c
PRINT_FILE = ft_putchar.c ft_putchar_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c ft_putstr.c ft_putstr_fd.c 
STR_FILE = ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strequ.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c

# Variables et chemins
SRC = $(addprefix $(SRC_PATH)char/, $(CHAR_FILE))\
$(addprefix $(SRC_PATH)conversion/, $(CONV_FILE))\
$(addprefix $(SRC_PATH)is/, $(IS_FILE))\
$(addprefix $(SRC_PATH)list/, $(LIST_FILE))\
$(addprefix $(SRC_PATH)memory/, $(MEM_FILE))\
$(addprefix $(SRC_PATH)print/, $(PRINT_FILE))\
$(addprefix $(SRC_PATH)string/, $(STR_FILE))

OBJ = $(SRC:.c=.o)
INC = $(addprefix $(INC_PATH), $(INC_FILE))

# Règles
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(MAGEN)Création de la bibliothèque $(NAME)"
	@ar rc $(NAME) $(OBJ)
	@echo "Création de l'index pour $(NAME)$(RESET)"
	@ranlib $(NAME)

## Permet de recompiler si un header est modifié
$(OBJ): $(INC)

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
