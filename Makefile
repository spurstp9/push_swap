CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpadded -fsanitize=address,undefined -g3
CHECKER_NAME = checker
PUSH_SWAP_NAME = push_swap

LIB_FOLDER = ./libft/
LIB_INC = ./libft/includes
LIB_NAME = libft.a
LIB_FLAGS = -L $(LIB_FOLDER) -lft
LIB = $(addprefix $(LIB_FOLDER), $(LIB_NAME))

SRC_FOLDER = ./src/
OBJ_FOLDER = ./obj/
SRC_FILES = apply_instr.c check_args.c check_args2.c check_instr.c check_order.c \
				check_stdin.c chunk_sort.c chunk_sort2.c ft_p.c ft_r.c ft_rr.c ft_s.c \
				main_checker.c main_push_swap.c replace_values_by_rank.c selection_sort.c \
				sort_last_three.c utils.c utils2.c
SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

CHECKER_OBJ_FILES = apply_instr.o \
						check_args.o \
						check_args2.o \
						check_instr.o \
						check_order.o \
						ft_p.o \
						ft_r.o \
						ft_rr.o \
						ft_s.o \
						main_checker.o \
						utils.o \
						utils2.o
CHECKER_OBJ = $(addprefix $(OBJ_FOLDER), $(CHECKER_OBJ_FILES))
PUSH_SWAP_OBJ_FILES = apply_instr.o \
						check_args.o \
						check_args2.o \
						check_order.o \
						chunk_sort.o \
						chunk_sort2.o \
						ft_p.o \
						ft_r.o \
						ft_rr.o \
						ft_s.o \
						main_push_swap.o \
						replace_values_by_rank.o \
						selection_sort.o \
						sort_last_three.o \
						utils.o \
						utils2.o
PUSH_SWAP_OBJ = $(addprefix $(OBJ_FOLDER), $(PUSH_SWAP_OBJ_FILES))

HDR_FOLDER = ./inc/
HDR_FILES = prototypes.h structs.h
HDR = $(addprefix $(HDR_FOLDER), $(HDR_FILES))

all: $(OBJ_FOLDER) $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIB_FLAGS) -o $(CHECKER_NAME)
	@echo "\n\033[1m\033[3m$(CHECKER_NAME)\033[0m [\033[32mOK\033[0m]\n"

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIB_FLAGS) -o $(PUSH_SWAP_NAME)
	@echo "\n\033[1m\033[3m$(PUSH_SWAP_NAME)\033[0m [\033[32mOK\033[0m]"

$(LIB): FORCE
	@echo "\n"
	@make -C $(LIB_FOLDER)

$(OBJ_FOLDER):
	@mkdir $@

$(OBJ_FOLDER)%.o:$(SRC_FOLDER)%.c $(HDR)
	@$(CC) $(CFLAGS) -I$(HDR_FOLDER) -I$(LIB_INC) -c -o $@ $<
	@echo "$* [Compiling...]"
	@echo "\033[A\033[K\033[A"
	@echo "$*.o [\033[32mOK\033[0m]"

clean:
	@make -C $(LIB_FOLDER) clean
	@rm -rf $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	@rm -rf $(OBJ_FOLDER)
	@echo "Object files related to push_swap and checker deleted"

fclean: clean
	@make -C $(LIB_FOLDER) fclean
	@rm -rf $(CHECKER_NAME)
	@rm -rf $(PUSH_SWAP_NAME)
	@echo "$(PUSH_SWAP_NAME) deleted"
	@echo "$(CHECKER_NAME) deleted"

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
