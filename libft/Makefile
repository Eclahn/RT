## Name of Project

NAME = libft.a

## Color for compilating (blue)

COLOR = \0033[1;34m

## List of Directories

INC_DIR = includes
OBJ_DIR = obj
SRC_DIR = src

DISPLAY_DIR = display
INTEGER_DIR = integer
LIST_DIR = list
MATRIX_DIR = matrix
MEMORY_DIR = memory
OTHER_DIR = other
PRINTF_DIR = printf
STRING_DIR = string

## Compilating Utilities

FLAGS = -Wall -Wextra -Werror
INC = $(INC_DIR:%=-I ./%)
CC = clang $(FLAGS) $(INC)

## List of Functions

DISPLAY_FT = ft_putchar \
			ft_putchar_fd \
			ft_putstr \
			ft_putstr_fd \
			ft_putnstr \
			ft_putnstr_fd \
			ft_putendl \
			ft_putendl_fd \
			ft_putnbr \
			ft_putnbr_fd \
			ft_boardprint \
			ft_intboardprint \
			ft_gnl

INTEGER_FT = ft_itoa \
			ft_isdigit \
			ft_isnumber \
			ft_ishexa \
			ft_pwr \
			ft_intboardset

LIST_FT = ft_lstnew \
			ft_lstdelone \
			ft_lstdel \
			ft_lstadd \
			ft_lstiter \
			ft_lstmap \
			ft_lstend \
			ft_lstinser \
			ft_lstinser_sorted \
			ft_lstlen \
			ft_lstshift

MATRIX_FT = ft_mtrx_mult \
			ft_mtrx_vector_mult \
			ft_mat_rxyz

MEMORY_FT = ft_memalloc \
			ft_memdel \
			ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memccpy \
			ft_memmove \
			ft_memchr \
			ft_memcmp

OTHER_FT = ft_atoi_base \
			ft_isalnum \
			ft_isascii \
			ft_isspace \
			ft_swap \
			ft_isprint

PRINTF_FT = ft_printf \
 			pf_solve_flags \
 			pf_apply_flags \
 			pf_itoa

STRING_FT = ft_strlen \
			ft_strdup \
			ft_strcpy \
			ft_strncpy \
			ft_strcat \
			ft_strncat \
			ft_strlcat \
			ft_strchr \
			ft_strrchr \
			ft_strstr \
			ft_strnstr \
			ft_strcmp \
			ft_strncmp \
			ft_strnew \
			ft_strdel \
			ft_strclr \
			ft_striter \
			ft_striteri \
			ft_strmap \
			ft_strmapi \
			ft_strequ \
			ft_strnequ \
			ft_strsub \
			ft_strjoin \
			ft_strtrim \
			ft_strsplit \
			ft_boardset \
			ft_atoi \
			ft_toupper \
			ft_tolower \
			ft_isalpha \
			ft_wtoc \
			ft_wstrtostr \
			ft_strtoupper \
			ft_input

## List of Utilities

SRC = $(DISPLAY_FT:%=$(SRC_DIR)/$(DISPLAY_DIR)/%.c) \
		$(INTEGER_FT:%=$(SRC_DIR)/$(INTEGER_DIR)/%.c) \
		$(LIST_FT:%=$(SRC_DIR)/$(LIST_DIR)/%.c) \
		$(MATRIX_FT:%=$(SRC_DIR)/$(MATRIX_DIR)/%.c) \
		$(MEMORY_FT:%=$(SRC_DIR)/$(MEMORY_DIR)/%.c) \
		$(OTHER_FT:%=$(SRC_DIR)/$(OTHER_DIR)/%.c) \
		$(PRINTF_FT:%=$(SRC_DIR)/$(PRINTF_DIR)/%.c) \
		$(STRING_FT:%=$(SRC_DIR)/$(STRING_DIR)/%.c)

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(DISPLAY_DIR:%=$(OBJ_DIR)/%) \
			$(INTEGER_DIR:%=$(OBJ_DIR)/%) \
			$(LIST_DIR:%=$(OBJ_DIR)/%) \
			$(MATRIX_DIR:%=$(OBJ_DIR)/%) \
			$(MEMORY_DIR:%=$(OBJ_DIR)/%) \
			$(OTHER_DIR:%=$(OBJ_DIR)/%) \
			$(PRINTF_DIR:%=$(OBJ_DIR)/%) \
			$(STRING_DIR:%=$(OBJ_DIR)/%)


## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)Libft\t\t\0033[1;30m[All OK]\0033[1;37m"

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)Creating    : \0033[0;32m$@\0033[1;37m"

$(SRC):

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@
	@echo "$(COLOR)Compilating : \0033[0;32m$(@:$(OBJ_DIR)/%=%)\0033[1;37m"

$(NAME): $(OBJ_DIRS) $(SRC)
	@$(MAKE) $(OBJ)
	@echo "$(COLOR)Objects\t\t\0033[0;32m[Created]\0033[1;37m"
	@ar rcs $@ $(OBJ)
	@echo "$(COLOR)$(NAME)\t\t\0033[0;32m[Created]\0033[1;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Objects\t\t\0033[0;31m[Deleted]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[0;31m[Deleted]\0033[1;37m"

re: fclean all

norme:
	@norminette $(SRC) $(INC_DIR)/

.PHONY: all clean fclean re norme
