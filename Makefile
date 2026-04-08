NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra -I. -I./libft

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = src/main.c \
src/parser.c \
src/moves/pushing.c \
src/moves/rotating.c \
src/moves/rrotating.c \
src/moves/swapping.c \
utils/frees.c \
utils/ft_safe_atoi.c \
utils/stack_mngr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re