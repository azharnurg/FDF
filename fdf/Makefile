# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurgali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 00:55:08 by anurgali          #+#    #+#              #
#    Updated: 2019/05/27 00:55:11 by anurgali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

CC		= gcc

FLAG	= -Wall -Wextra -Werror
MLX		= -I./minilibx_macos -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCS	= main.c \
			setup.c\
			draw.c\
			draw1.c\
			validation.c\
			color.c\
			rotation.c\

OBJ 	= ${SRCS:.c=.o}
INCLUDE = -I fdf.h -L ./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(FLAG) $(INCLUDE) $(MLX) $(OBJ) -o $(NAME)
clean:
				@/bin/rm -f $(OBJ)

fclean: clean
				@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
