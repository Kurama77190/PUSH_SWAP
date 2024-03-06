# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 19:43:50 by sben-tay          #+#    #+#              #
#    Updated: 2024/03/06 23:00:18 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Définitions de base

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
CPPFLAGS = -I./include
#=================================================__SRC__OF__PROJECT__=============================================================================
SRC_LIB = 		./src/lib/ft_argvlen.c ./src/lib/ft_atoi.c ./src/lib/ft_free_split.c ./src/lib/ft_is_atoi_overflow.c \
				./src/lib/ft_is_space.c ./src/lib/ft_lstadd_back.c ./src/lib/ft_lstadd_front.c ./src/lib/ft_lstclear.c \
				./src/lib/ft_lstnew.c ./src/lib/ft_lstlast.c ./src/lib/ft_lstsize.c ./src/lib/ft_print_lst.c ./src/lib/ft_putstr_fd.c \
				./src/lib/ft_split.c ./src/lib/ft_strsjoin.c ./src/lib/ft_strlen.c

SRC_SECURITY =  ./src/security/ft_security.c ./src/security/ft_security_utils.c ./src/main.c

SRC_COMMANDS = ./src/commands/commands_push.c ./src/commands/commands_reverse.c ./src/commands/commands_rotate.c ./src/commands/commands_swap.c

SRC_PUSH_SWAP = ./src/push_swap/move_and_initializing/initializing_a.c ./src/push_swap/move_and_initializing/initializing_b.c \
				./src/push_swap/move_and_initializing/move_a_to_b.c ./src/push_swap/move_and_initializing/move_b_to_a.c \
				./src/push_swap/push_swap_utils.c ./src/push_swap/push_swap.c

SRC_ALL = $(SRC_LIB) $(SRC_SECURITY) $(SRC_COMMANDS) $(SRC_PUSH_SWAP)
#==================================================================================================================================================

# Définitions des fichiers sources et objets

OBJ = $(SRC_ALL)

# Règles des couleurs

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CYAN = \033[0;36m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
BLANC = \033[0;37m

all:	$(NAME)

$(NAME):
#===========================================ASCI_MOD===========================================
	@echo "$(MAGENTA)"
	@echo " _____  _    _  _____ _    _    _______          __     _____  "
	@echo "|  __ \| |  | |/ ____| |  | |  / ____\ \        / /\   |  __ \ "
	@echo "| |__) | |  | | (___ | |__| | | (___  \ \  /\  / /  \  | |__) |"
	@echo "|  ___/| |  | |\___ \|  __  |  \___ \  \ \/  \/ / /\ \ |  ___/ "
	@echo "| |    | |__| |____) | |  | |  ____) |  \  /\  / ____ \| |     "
	@echo "|_|     \____/|_____/|_|  |_| |_____/    \/  \/_/    \_\_|     "
	@echo "                                                    by sben-tay"
	@echo "$(GREEN)"

	@echo -n "Compilation progress: ["
	@for i in $$(seq 1 50); do \
        sleep 0.1; \
        echo -n "#"; \
    done
	@echo "] 100 %"

	@echo "$(CYAN)Starting compilation..."
	@sleep 5 # Simule la compilation
	@echo "Done !"
#=============================================================================================

# Règle pour créer l'exécutable push_swap

	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME)

# Règles pour nettoyer les fichiers objets et l'exécutable

clean:
	@echo "$(RED)Cleaning up..."
	@rm -f $(NAME)
	@echo "Done !"

fclean: clean

# Règle pour recompiler
re: fclean all

# Pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean fclean re