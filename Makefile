# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 12:32:09 by vzamyati          #+#    #+#              #
#    Updated: 2018/07/24 12:32:11 by vzamyati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
WWW = -Wall -Wextra -Werror
MLX = -lmlx -framework AppKit -framework OpenGl -O3

SRC_FILES = 	main.c \
				events.c \
				player.c \
				map.c \
				clean.c \
				texture.c \
				raycasting.c \
				draw.c \
				moves.c \
				adds.c 


OBJ_NAME = $(SRC_FILES:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC = -I$(INC_DIR)
INC_DIR = include/
LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = obj/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@ echo "\033[32;1mLIB CREATED\033[0m"
	$(CC) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft $(FLAGS) $(MLX)
	@ echo "\033[32;1mCOMPILING FINISHED\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@ echo "\033[33;1mLINKING [$@]\033[0m"
	$(CC) $(WWW) -o $@ -c $< $(INC)

norm:
	@ echo "\033[35;1mwait for norminette\033[0m"
	@norminette ./libft/
	@norminette ./include
	@norminette ./srcs

clean:
	@make -C $(LIB_DIR) clean --silent
	@rm -rf $(OBJ_DIR)
	@ echo "\033[31;mREMOVE OBJECT FILES\033[0m"

fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	@rm -f $(NAME)
	@ echo "\033[36;1mREMOVE BINARY FILES\033[0m"

re: fclean all

.PHONY: clean fcelan all re
