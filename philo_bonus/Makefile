# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 08:03:20 by agraille          #+#    #+#              #
#    Updated: 2025/02/22 14:49:20 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS_NAME= philo_bonus
CC=cc
CFLAGS=-Wall -Wextra -Werror -g3
SRC = src/main_bonus.c src/philo_bonus.c src/utils/parsing_bonus.c src/utils/struct_utils_bonus.c src/utils/time_utils_bonus.c \
src/philo_action_bonus.c
BONUS_SRC = src/main_bonus.c src/philo_bonus.c src/utils/parsing_bonus.c src/utils/struct_utils_bonus.c src/utils/time_utils_bonus.c \
src/philo_action_bonus.c
OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/,$(BONUS_SRC:%.c=%.o))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Success! ✅ ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)
	@echo "$(GREEN)╔═════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Bonus Success! ✅ ║$(RESET)"
	@echo "$(GREEN)╚═════════════════════════════════╝$(RESET)"

$(OBJ_DIR)/%.o: %.c Makefile ./include/philo_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean :
	@rm -rf $(OBJ) $(BONUS_OBJ) $(OBJ_DIR)/
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean :
	@rm -rf $(NAME) $(OBJ) $(OBJ_DIR) $(BONUS_NAME) $(BONUS_OBJ)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

re : fclean all

.PHONY : all re fclean clean
