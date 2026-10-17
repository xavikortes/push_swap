NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDES =  -Isrc/analyzer \
			-Isrc/parser \
			-Isrc/solver \
			-Isrc/stacker \
			-Isrc/bench \
			-Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_INCLUDE = -I$(LIBFT_DIR)/

SRC =   src/analyzer/analyzer \
		src/parser/parser \
		src/parser/parser_utils \
		src/stacker/stacker \
		src/stacker/stack_utils \
		src/stacker/stack_operations \
		src/solver/solver \
		src/solver/bubble_sort \
		src/solver/chunk_sort \
		src/solver/chunk_utils \
		src/solver/merge_sort \
		src/bench/bench

SRCS = $(addsuffix .c, $(SRC))

OBJ_DIR = objs
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

MAIN_OBJ = $(OBJ_DIR)/src/main.o
BONUS_OBJ = $(OBJ_DIR)/src/checker.o

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(LIBFT) $(OBJS) $(MAIN_OBJ)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) compiled succesfully!"

$(BONUS): $(LIBFT) $(OBJS) $(BONUS_OBJ)
	@echo "Linking $(BONUS)..."
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJS) $(LIBFT) -o $(BONUS)
	@echo "$(BONUS) compiled succesfully!"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

clean:
	@echo "Cleaning project objects..."
	$(RM) $(OBJ_DIR)
	@echo "Cleaning libft completed!"
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Deep cleaning project executable..."
	$(RM) $(NAME)
	$(RM) $(BONUS)
	@echo "Deep cleaning libft archive..."
	@make -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "Rebuilding project..."

.PHONY: all bonus clean fclean re
