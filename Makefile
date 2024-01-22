# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.paris.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 19:43:50 by sben-tay          #+#    #+#              #
#    Updated: 2024/01/22 20:44:58 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/parsing.c \

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

all : libft $(NAME)


libft:
	$(MAKE) -C LIBFT -f Makefile

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean :
	$(MAKE) -C LIBFT -f Makefile clean
	$(RM) $(OBJ)

fclean : clean
	$(MAKE) -C LIBFT -f Makefile fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re libft