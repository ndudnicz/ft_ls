NAME = ft_ls

CC = gcc

FLAGS = -Wextra -Wall -O2 #-fsanitize=address #-g #-Werror

PATH_SRC = src

PATH_OBJ = obj

PATH_INCLUDES = includes/
LIB_INCLUDES = libft/includes/

SRC =	\
main.c \
error.c \
options.c \
entry_list.c \
entry_parse.c \
entry_push_back.c \
entry_push_sort.c \
compare_lex.c \
compare_time.c \
display.c \
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
