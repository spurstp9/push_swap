CHECKER_NAME = checker

PUSH_SWAP_NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -Wpadded -fsanitize=address,undefined -g3

LIB_FOLDER = ./libft/
LIB_INC = ./libft/includes
LIB_NAME = libft.a
LIB_FLAGS = -L $(LIB_FOLDER) -lft
LIB = $(addprefix $(LIB_FOLDER), $(LIB_NAME))

SRC_FOLDER = ./src/

CHECKER_SRC_FILES = apply_instr.c check_order.c ft_p.c ft_r.c ft_rr.c \
		ft_s.c main_checker.c parsing.c utils.c utils2.c
CHECKER_SRC = $(addprefix $(SRC_FOLDER), $(CHECKER_SRC_FILES))

PUSH_SWAP_SRC_FILES = apply_instr.c check_order.c chunk_sort.c \
		chunk_sort2.c ft_p.c ft_r.c ft_rr.c ft_s.c main_push_swap.c \
		parsing.c replace_values_by_rank.c selection_sort.c sort_last_three.c \
	utils.c utils2.c
PUSH_SWAP_SRC = $(addprefix $(SRC_FOLDER), $(PUSH_SWAP_SRC_FILES))

HDR_FOLDER = ./inc/
HDR_FILES = prototypes.h structs.h
HDR = $(addprefix $(HDR_FOLDER), $(HDR_FILES))

OBJ_FOLDER = ./obj/

CHECKER_OBJ_FILES = $(CHECKER_SRC_FILES:.c=.o)
CHECKER_OBJ = $(addprefix $(OBJ_FOLDER), $(CHECKER_OBJ_FILES))

PUSH_SWAP_OBJ_FILES = $(PUSH_SWAP_SRC_FILES:.c=.o)
PUSH_SWAP_OBJ = $(addprefix $(OBJ_FOLDER), $(PUSH_SWAP_OBJ_FILES))

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJ) $(LIB)
	@echo "$(CHECKER_NAME) [Compiling...]"
	@gcc $(CHECKER_OBJ) $(LIB_FLAGS) -fsanitize=address,undefined -g3 -o $(CHECKER_NAME)
	@echo "\033[A\033[K\033[A"
	@echo "\033[1m$(CHECKER_NAME)\033[0m [\033[32mOK\033[0m]"

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ) $(LIB)
	@echo "$(PUSH_SWAP_NAME) [Compiling...]"
	@gcc $(PUSH_SWAP_OBJ) $(LIB_FLAGS) -fsanitize=address,undefined -g3 -o $(PUSH_SWAP_NAME)
	@echo "\033[A\033[K\033[A"
	@echo "\033[1m$(PUSH_SWAP_NAME)\033[0m [\033[32mOK\033[0m]"

$(LIB):
	@make -C $(LIB_FOLDER)

$(OBJ_FOLDER)%.o:$(SRC_FOLDER)%.c $(HDR)
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(CFLAGS) -I$(HDR_FOLDER) -I$(LIB_INC) -c -o $@ $<
	@echo "$* [Compiling...]"
	@echo "\033[A\033[K\033[A"
	@echo "$*.o [\033[32mOK\033[0m]"

clean:
	@rm -rf $(OBJ) $(OBJ_FOLDER)
	@echo "Object files related to push_swap deleted"

fclean: clean
	@make -C $(LIB_FOLDER) fclean
	@rm -rf $(CHECKER_NAME)
	@rm -rf $(PUSH_SWAP_NAME)
	@echo "$(PUSH_SWAP_NAME) deleted"
	@echo "$(CHECKER_NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
