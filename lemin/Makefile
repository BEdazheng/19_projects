NAME = lem-in

SRC = srcs/main.c srcs/li_utils.c srcs/li_get_data.c srcs/li_check_data.c \
	  srcs/manage_links.c srcs/path_finder.c srcs/path_finder_tools.c \
	  srcs/path_finder_functions.c srcs/path_saver.c srcs/get_best_set.c \
	  srcs/trashcan.c

OBJ1 = $(SRC:srcs/%=%)

OBJ = $(OBJ1:%.c=%.o)

LIB = libft/libft.a

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) -c $(SRC)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
