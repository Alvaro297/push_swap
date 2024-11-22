CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
	  Nodes_moves/append_modifiy.c \
      Nodes_moves/push.c \
      Nodes_moves/rotates.c \
	  Nodes_moves/free_nodes.c \
      Nodes_moves/set_values.c \
      Nodes_moves/swaps.c \
      sort_stacks/sort_stack.c \
      Utils/utils_push_swap.c \
      Validations_initializer/init_values.c \
      Validations_initializer/move_nodes.c \
      Validations_initializer/move_values.c \
      Validations_initializer/prints_relevants.c \
      Validations_initializer/validations.c
OBJ = $(SRC:.c=.o)
TARGET = push_swap

LIBFT_DIR = ./libft_entrega
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(TARGET)

$(TARGET): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(TARGET)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re