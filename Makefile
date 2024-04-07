# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 11:41:20 by bwach             #+#    #+#              #
#    Updated: 2024/04/06 17:00:56 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors
GREEN = \033[0;32m
RED = \033[0;31m
CYAN = \033[0;36m
DEFAULT = \033[0m

#Name and Aliases
NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror
LEAKS = leaks --atExit --
RM = rm -f
PRINTF = printf
BIN = philo

#Files and paths
HEADER_SRCS = Philosophers.h 
HEADER_DIR = include/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS = main.c philo_func.c 
MPATH_DIR = srcs/
MPATH = $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M = $(MPATH:.c=.o)

UTIL_SRCS = time.c utils.c init_utils.c philo_utils.c groundcontrol_to.c free_them.c
UTIL_DIR = utils/
UTILS = $(addprefix $(UTIL_DIR), $(UTIL_SRCS))
OBJ_U = $(UTILS:.c=.o)

#Commands
%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -I $(HEADER_DIR) -c $< -o $@

all: $(NAME) norminette

norminette: 
	@$(PRINTF) "$(CYAN)\nCheck with dat Norminette: $(BIN) $(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(MPATH_DIR) $(UTIL_DIR)/*.c
	@norminette -R CheckDefine $(MPATH_DIR) $(UTIL_DIR)/*.c
	@echo "$(CYAN)\nNorminette done and validated 🤣\n $(DEFAULT)"

$(NAME): $(OBJ_M) $(OBJ_U)
	@echo "$(GREEN)-----------------------------------------------$(DEFAULT)"
	@echo "$(CYAN)\n            Compiling $(NAME)...			\n$(DEFAULT)"
	@echo "$(GREEN)-----------------------------------------------\n\n$(DEFAULT)"
	@echo "$(GREEN)██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗$(DEFAULT)"
	@echo "$(GREEN)██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝$(DEFAULT)"
	@echo "$(GREEN)██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗$(DEFAULT)"
	@echo "$(GREEN)██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║$(DEFAULT)"
	@echo "$(GREEN)██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║$(DEFAULT)"
	@echo "$(GREEN)╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝$(DEFAULT)"
	@$(CC) $(OBJ_U) $(OBJ_M) -o $(NAME)

clean:
	@$(RM) $(OBJ_M)
	@$(RM) $(OBJ_U)
	@echo -e: "$(RED)object files deleted!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo -e: "$(RED)$(NAME) deleted!$(DEFAULT)"

re: fclean all

run: re
	$(LEAKS) ./$(NAME) 10 1000 200 200 2

.PHONY: all clean fclean re