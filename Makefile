NAME = ft_ls

CC = gcc

FLAGS = -g -Wextra -Wall -fsanitize=address #-Werror

PATH_SRC = src

PATH_OBJ = obj

PATH_INCLUDES = includes/
LIB_INCLUDES = libft/includes/

SRC =	\
main.c \
error.c \
options.c \
entry_list.c \
entry_parse.c

OBJ = $(SRC:%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) -o $@ $(OBJ) -L. -lft -L. -lftasm

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c
	$(CC) $(FLAGS) -MMD -o $@ -c $< -I $(PATH_INCLUDES) -I $(LIB_INCLUDES)

clean:
	make clean -C libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

-include $(OBJ:.o=.d)
