# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 08:03:20 by agraille          #+#    #+#              #
#    Updated: 2025/02/24 13:37:42 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all re fclean clean

NAME = philo
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC = src/main.c src/philo.c src/utils/parsing.c src/utils/struct_utils.c src/utils/time_utils.c \
src/philo_action.c src/utils/threads_utils.c src/utils/mutex_utils.c
OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Success! ✅ ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

$(OBJ_DIR)/%.o: %.c Makefile ./include/philo.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean :
	@rm -rf $(OBJ) $(OBJ_DIR)/
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean :
	@rm -rf $(NAME) $(OBJ) $(OBJ_DIR)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

re : fclean all
