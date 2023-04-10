SRC = check.c \
	get_next_line_utils.c \
	get_next_line.c \
	main.c \
	split.c \
	utils.c \
	window.c \
	position.c \
	checkpath.c \
	mv_right_left.c \
	mv_up_down.c \
	creatwindow.c \
	free.c \
	check_wall.c \

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = so_long.h
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean : 
		rm -rf $(OBJ)
fclean : clean
		rm -rf $(NAME)
re : clean fclean all