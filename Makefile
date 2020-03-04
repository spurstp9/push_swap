CHECKER_NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB_FOLDER = ./libft/
LIB_INC = ./libft/includes
LIB_NAME = ./libft/includes
LIB_FLAGS = -L $(LIB_FOLDER) -lft
LIB = $(addprefix $(LIB_FOLDER), $(LIB_NAME))

SRC_FOLDER = ./src/
SRC_FILES = apply_instr.c ft_p.c ft_r.c ft_rr.c ft_s.c main_checker.c parsing.c
SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

HDR_FOLDER = ./inc/
HDR_FILES = push_swap.h
HDR = $(addprefix $(HDR_FOLDER), $(HDR_FILES))

OBJ_FOLDER = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_FOLDER), $(OBJ_FILES))

all: $(CHECKER_NAME)

$(CHECKER_NAME): $(OBJ) $(LIB)
	@echo "$(CHECKER_NAME) [Compiling...]"
	@gcc $(OBJ) $(LIB_FLAGS) -o $(CHECKER_NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(CHECKER_NAME) [\033[32mOK\033[0m]"

$(LIB):
	@echo "Libft compilation [...]"
	@make -C $(LIB_FOLDER)
	@echo "\033[A\033[K\033[A"
	@echo "Libft compilation [\033[32mOK\033[0m]"

$(OBJ_FOLDER)%.o:$(SRC_FOLDER)%.c $(HDR)
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(CFLAGS) -I$(HDR_FOLDER) -I$(LIB_INC) -c -o $@ $<

clean:
	@make -C $(LIB_FOLDER) clean
	@rm -rf $(OBJ) $(OBJ_FOLDER)

fclean: clean
	@make -C $(LIB_FOLDER) fclean
	@rm -rf $(CHECKER_NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re