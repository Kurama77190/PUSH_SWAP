# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 19:43:50 by sben-tay          #+#    #+#              #
#    Updated: 2024/01/23 17:53:39 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Définitions de base
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap
LIBFT = ./LIBFT
LIBFT_A = $(LIBFT)/libft.a
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)
	
# Règle principale
all: libft $(NAME)
# Règle pour créer votre programme principal
$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT) -lft -o $(NAME)

# Règle pour compiler libft
libft:
	$(MAKE) -C $(LIBFT) bonus

# Règle pour créer l'exécutable push_swap
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME)

# Règles pour nettoyer les fichiers objets et l'exécutable
clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

# Règle pour recompiler
re: fclean all

# Pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean fclean re libft
