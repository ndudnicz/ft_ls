NAME = ft_ls
CC = gcc
FLAGS = -Werror -Wextra -Wall -std=c89 -O2 -flto# -g -fsanitize=address
PATH_SRC = src
PATH_OBJ = obj
PATH_INCLUDES = includes/
LIB_INCLUDES = libft/includes/
LIBFT.A = libft.a
LIBFTASM.A = libftasm.a

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
display_long_format_line.c \
misc.c \
free.c \
args_compare_lex.c \
args_compare_time.c \
run.c \
check_opendir.c \
set_sizes.c

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
	$(RM) $(NAME) $(LIBFT.A) $(LIBFTASM.A)

re: fclean all

-include $(OBJ:.o=.d)
