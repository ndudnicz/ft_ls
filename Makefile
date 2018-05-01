NAME = ft_ls

CC = gcc

FLAGS = -Wextra -Wall #-Werror -O3 #-flto

PATH_SRC = src

PATH_OBJ = obj

PATH_INCLUDES = includes/
LIB_INCLUDES = libft/includes/

SRC =	\
main.c \
error.c \
options.c \
entry_list.c \
entry_list_long.c \
entry_init.c \
entry_init_long.c \
entry_parse.c \
entry_parse_long.c \
entry_push_sort.c \
compare_lex.c \
compare_time.c \
display.c \
display_long.c \
misc.c \
free.c

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
