NAME = wolf3d

FLAGS = -Wall -Wextra -Werror -I wolf3d.h

MLX = -lmlx -framework AppKit -framework OpenGl -O3

LIB = ./libft/libft.a

SRC_FILES = 	main.c \
				events.c \
				env.c


BIN_FILES = $(SRC_FILES:.c=.o)

all: makelib $(NAME)

makelib:
	make -C ./libft/

libclean:
	make -C ./libft/ clean

libfclean:
	make -C ./libft/ fclean

$(NAME): $(BIN_FILES)
	gcc -o $(NAME) $(BIN_FILES) $(FLAGS) $(MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BIN_FILES)

fclean: libfclean clean
	/bin/rm -f $(NAME)

re: fclean all