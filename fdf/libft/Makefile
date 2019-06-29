# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurgali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/08 01:40:54 by anurgali          #+#    #+#              #
#    Updated: 2019/06/01 05:20:57 by anurgali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_memalloc.c	ft_putendl.c	ft_strcpy.c		ft_strmapi.c	ft_strsub.c
SRC +=	ft_memccpy.c	ft_putendl_fd.c	ft_strdel.c		ft_strncat.c	ft_strtrim.c
SRC +=	ft_atoi.c		ft_memchr.c		ft_putnbr.c		ft_strdup.c		ft_strncmp.c	ft_tolower.c
SRC +=	ft_bzero.c		ft_memcmp.c		ft_putnbr_fd.c	ft_strequ.c		ft_strncpy.c	ft_toupper.c
SRC +=	ft_isalnum.c	ft_memcpy.c		ft_putstr.c		ft_striter.c	ft_strnequ.c	
SRC +=	ft_isalpha.c	ft_memdel.c		ft_putstr_fd.c	ft_striteri.c	ft_strnew.c
SRC +=	ft_isascii.c	ft_memmove.c	ft_strcat.c		ft_strjoin.c	ft_strnstr.c
SRC	+=	ft_isdigit.c	ft_memset.c		ft_strchr.c		ft_strlcat.c	ft_strrchr.c
SRC +=	ft_isprint.c	ft_putchar.c	ft_strclr.c		ft_strlen.c		ft_strsplit.c
SRC	+=	ft_itoa.c		ft_putchar_fd.c	ft_strcmp.c		ft_strmap.c		ft_strstr.c
SRC +=	ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstiter.c	ft_lstmap.c
SRC +=	ft_lstadd.c 	ft_isupper.c 	ft_islower.c 	ft_wdl.c 		ft_wdcount.c
SRC +=	ft_spacecheck.c ft_get_next_line.c	ft_swap_float.c

OBJECTS = *.o

INCLUDE = libft.h

all:	$(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC) -I $(INCLUDE)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
