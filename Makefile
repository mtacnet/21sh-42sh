# Nom
NAME = 42sh
PROJECT = 42sh

# Détection de l'OS
OS = $(shell uname -s)

# Options de compilation
CC = @gcc
CFLAGS = -Wall -Werror -Wextra
ifeq ($(OS), Linux)
	CFLAGSUP = -Wno-sign-compare -Wno-empty-body
else
	CFLAGSUP = -Wno-sign-compare
endif
CPPFLAGS =	-I $(INC_PATH) -I $(LIB_INC) -I $(LIBSUP_INC) -I $(ENV_INC)  \
			-I $(LINE_INC) -I $(CMP_INC) -I $(LIBSUP2_INC) -I $(ERROR_INC) -I $(PARSER_INC) -I $(HIST_INC) -I $(EXEC_INC) -I $(BUILT_INC) -I $(HERE_INC)

CLIB =	-L $(EXEC) -lexec -L $(HEREDOC) -lheredoc -L $(LINE) -llinput -L $(CMP) -lcomplete -L $(PARSER) -lparser\
		-L $(BUILT) -luiltins -L $(HIST) -lstory -L $(ENV) -lenv -L $(ERROR) -lerror\
		-L $(LIBSUP2) -lsup2 -L $(LIBSUP) -lsup -L $(LIBFT) -lft -ltermcap

# Fichiers d'en-tête
INC_PATH = includes/
INC_FILE = sh.h
INC = $(addprefix $(INC_PATH), $(INC_FILE))
SH = SH_INC=../../$(INC_PATH)

# Fichiers sources
SRC_PATH = src/
SRC_FILE = builtin.c env.c history.c line.c local.c quotes.c sh.c signal.c tools.c ft_expand_exclam.c ft_expand_dollar.c\
			ft_expand_index.c ft_expand_is.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

# Fichiers des bibliothèques
LIBFT = libft/
LIB_INC = $(LIBFT)includes/
LIB_FT = $(LIBFT)libft.a
FT = LIBFT_INC=../../libft/includes

LIBSUP = modules/libsup/
LIBSUP_INC = $(LIBSUP)includes/
LIB_SUP = $(LIBSUP)libsup.a
SUP = LIBSUP_INC=../libsup/includes

LIBSUP2 = modules/libsup2/
LIBSUP2_INC = $(LIBSUP2)includes/
LIB_SUP2 = $(LIBSUP2)libsup2.a
SUP2 = LIBSUP2_INC=../libsup2/includes

ERROR = modules/error/
ERROR_INC = $(ERROR)/includes/
LIB_ERROR = $(ERROR)/liberror.a
ERR = ERROR_INC=../error/includes

ENV = modules/environment/
ENV_INC = $(ENV)includes/
LIB_ENV = $(ENV)libenv.a
ENVI = ENV_INC=../environment/includes

LINE = modules/line_input/
LINE_INC = $(LINE)includes/
LIB_LINE = $(LINE)liblinput.a
LIN = LINE_INC=../line_input/includes

CMP = modules/completion/
CMP_INC = $(CMP)includes/
LIB_CMP = $(CMP)libcomplete.a
COMP = CMP_INC=../completion/includes

HIST = modules/history/
HIST_INC = $(HIST)includes/
LIB_HIST = $(HIST)libstory.a
HST = HIST_INC=../history/includes

PARSER = modules/parser/
PARSER_INC = $(PARSER)/includes/
LIB_PARSER = $(PARSER)libparser.a
PARS = PARSER_INC=../parser/includes

EXEC = modules/execution/
EXEC_INC = $(EXEC)/includes/
LIB_EXEC = $(EXEC)libexec.a
XC = EXEC_INC=../execution/includes

BUILT = modules/builtins/
BUILT_INC = $(BUILT)includes/
LIB_BUILT = $(BUILT)libuiltins.a
BLT = BUILT_INC=../builtins/includes

HEREDOC = modules/heredocs/
HERE_INC = $(HEREDOC)includes/
LIB_HERE = $(HEREDOC)libheredoc.a
HRD = HERE_INC=../heredocs/includes

# Règles de compilation
all: lib $(NAME)

$(NAME): Makefile $(LIB_FT) $(LIB_SUP) $(LIB_SUP2) $(LIB_ERROR) $(LIB_ENV) $(LIB_HIST) \
$(LIB_LINE) $(LIB_CMP) $(LIB_PARSER) $(LIB_EXEC) $(LIB_BUILT) $(LIB_HERE) $(OBJ)

	@echo "$(CYAN)Compilation de $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(CFLAGSUP) $(OBJ) $(CLIB) -o $(NAME)
	@rm -rf $(NAME).dSYM

$(OBJ): $(INC)

lib:
	@echo "$(VERT)Compilation...$(RESET)"
	@make -C $(LIBFT) all
	@make -C $(LIBSUP) $(FT) all
	@make -C $(LIBSUP2) $(FT) all
	@make -C $(ERROR) $(FT) all
	@make -C $(ENV) $(FT) $(SUP) $(ERR) all
	@make -C $(CMP) $(FT) $(SUP) $(ERR) all
	@make -C $(HIST) $(FT) $(SUP) $(ERR) all
	@make -C $(PARSER) $(FT) $(SUP2) $(ERR) all
	@make -C $(EXEC) $(SUP) $(FT) $(PARS) $(SUP2) $(ERR) $(ENVI) $(BLT) $(HST) $(HRD) all
	@make -C $(LINE) $(FT) $(SUP) $(ENVI) $(COMP) $(ERR) $(HRD) all
	@make -C $(HEREDOC) $(FT) $(SUP) $(HST) $(ENVI) $(LIN) $(COMP) $(ERR) all
	@make -C $(BUILT) $(FT) $(SUP) $(ENVI) $(HST) $(ERR) $(XC) $(PARS) $(SUP2) $(SH) all

clean: cleanproj
	@make -C $(LIBFT) clean
	@make -C $(LIBSUP) clean
	@make -C $(LIBSUP2) clean
	@make -C $(ERROR) clean
	@make -C $(ENV) clean
	@make -C $(CMP) clean
	@make -C $(HIST) clean
	@make -C $(PARSER) clean
	@make -C $(EXEC) clean
	@make -C $(LINE) clean
	@make -C $(BUILT) clean
	@make -C $(HEREDOC) clean

fclean: fcleanproj
	@make -C $(LIBFT) fclean
	@make -C $(LIBSUP) fclean
	@make -C $(LIBSUP2) fclean
	@make -C $(ERROR) fclean
	@make -C $(ENV) fclean
	@make -C $(CMP) fclean
	@make -C $(HIST) fclean
	@make -C $(PARSER) fclean
	@make -C $(EXEC) fclean
	@make -C $(LINE) fclean
	@make -C $(BUILT) fclean
	@make -C $(HEREDOC) fclean

re: fclean all

cleanproj:
	@echo "$(ROUGEC)Suppression des fichiers objets de $(NAME)$(RESET)"
	@rm -f $(OBJ)

fcleanproj: cleanproj
	@echo "$(ROUGEC)Suppression de l'exécutable $(NAME)$(RESET)"
	@rm -f $(NAME)

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

.PHONY: all lib clean fclean re doxygen cleandoxy
