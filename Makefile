# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.paris.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 19:43:50 by sben-tay          #+#    #+#              #
#    Updated: 2024/01/23 23:00:15 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Définitions de base
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I./includes
NAME = push_swap
PRINTF = ./includes/PRINTF
LIBFT = ./includes/LIBFT
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)
	
# Règle principale
all: 	libft $(NAME)

# Règle pour compiler libft
libft:
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	
# Règle pour créer l'exécutable push_swap
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(PRINTF) -lftprintf -L$(LIBFT) -lft -o $(NAME)

# Règles pour nettoyer les fichiers objets et l'exécutable
clean:
	$(MAKE) -C $(PRINTF) clean
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(PRINTF) fclean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

# Règle pour recompiler
re: fclean all

# Pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean fclean re libft
