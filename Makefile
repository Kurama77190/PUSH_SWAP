# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 19:43:50 by sben-tay          #+#    #+#              #
#    Updated: 2024/03/02 14:01:42 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Définitions de base
NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
CPPFLAGS = -I./include
BUILD = ./build
PRINTF = ./external/PRINTF
#=================================================__SRC__OF__PROJECT__=============================================================================
SRC_LIB = 		./src/lib/ft_argvlen.c ./src/lib/ft_atoi.c ./src/lib/ft_free_split.c ./src/lib/ft_is_atoi_overflow.c \
				./src/lib/ft_is_space.c ./src/lib/ft_lstadd_back.c ./src/lib/ft_lstadd_front.c ./src/lib/ft_lstclear.c \
				./src/lib/ft_lstnew.c ./src/lib/ft_lstlast.c ./src/lib/ft_lstsize.c ./src/lib/ft_print_lst.c ./src/lib/ft_putstr_fd.c \
				./src/lib/ft_split.c ./src/lib/ft_strsjoin.c
#==================================================================================================================================================
SRC_SECURITY =  ./src/security/ft_security.c ./src/security/ft_security_utils.c ./src/main.c
#==================================================================================================================================================
SRC_COMMANDS = ./src/commands/commands_push.c ./src/commands/commands_reverse.c ./src/commands/commands_rotate.c ./src/commands/commands_swap.c
#==================================================================================================================================================
SRC_PUSH_SWAP = ./src/push_swap/move_and_initializing/initializing_a.c ./src/push_swap/move_and_initializing/initializing_b.c \
				./src/push_swap/move_and_initializing/move_a_to_b.c ./src/push_swap/move_and_initializing/move_b_to_a.c \
				./src/push_swap/push_swap_utils.c ./src/push_swap/push_swap.c
#==================================================================================================================================================

SRC_ALL = $(SRC_LIB) $(SRC_SECURITY) $(SRC_COMMANDS) $(SRC_PUSH_SWAP)

OBJ = $(SRC_ALL:src/%.c=$(BUILD)/%.o)

# Crée le dossier BUILD si nécessaire
$(shell mkdir -p $(BUILD))

# Règle principale
all: 	printf $(NAME)

# Règle pour compiler printf
printf:
	$(MAKE) -C $(PRINTF)
	
# Règle pour créer l'exécutable push_swap
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -L$(PRINTF) -lftprintf -o $(NAME)

# Règle pour compiler les fichiers .c en .o et les déplacer dans BUILD
$(BUILD)/%.o: src/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Règles pour nettoyer les fichiers objets et l'exécutable
clean:
	$(MAKE) -C $(PRINTF) clean
	rm -f $(BUILD)/*.o

fclean: clean
	$(MAKE) -C $(PRINTF) fclean
	rm -f $(NAME)

# Règle pour recompiler
re: fclean all

# Pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean fclean re printf
