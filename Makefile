# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 11:41:20 by bwach             #+#    #+#              #
#    Updated: 2024/03/29 16:20:18 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors
GREEN = \033[0;32m
RED = \033[0;31m
CYAN = \033[0;36m
DEFAULT = \033[0m

#Name and Aliases
NAME = Philosophers
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
PRINTF = printf
BIN = Philosophers

#Files and paths
HEADER_SRCS = Philosophers.h 
HEADER_DIR = include/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS = main.c  
MPATH_DIR = srcs/
MPATH = $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M = $(MPATH:.c=.o)

UTILS_SRCS = time.c
UTIL_DIR = utils/
UTILS = $(addprefix $(UTIL_DIR), $(UTILS_SRCS))
OBJ_U = $(UTILS:.c=.o)

#Commands
%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER_DIR)

all: $(NAME) norminette

norminette: norminette:
	@$(PRINTF) "$(CYAN)\nCheck with dat Norminette: $(BIN) $(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(MPATH_DIR) $(UTIL_DIR) $(LBFT_DIR)/*.c
	@norminette -R CheckDefine $(MPATH_DIR) $(UTIL_DIR) $(LIBFT_DIR)/*.c
	@echo "$(CYAN)\nNorminette done and validated 🤣\n $(DEFAULT)"

$(NAME): $(OBJ_M)
	@echo "$(GREEN)-----------------------------------------------$(DEFAULT)"
	@echo "$(CYAN)\n            Compiling $(NAME)...			\n$(DEFAULT)"
	@echo "$(GREEN)-----------------------------------------------$(DEFAULT)"
	@echo "$(GREEN)██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗$(DEFAULT)"
	@echo "$(GREEN)██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝$(DEFAULT)"
	@echo "$(GREEN)██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗$(DEFAULT)"
	@echo "$(GREEN)██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║$(DEFAULT)"
	@echo "$(GREEN)██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║$(DEFAULT)"
	@echo "$(GREEN)╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝$(DEFAULT)"
	@$(CC) $(OBJ_M) $(OBJ_U) -o $(NAME)

clean:
	@$(RM) $(OBJ_M)
	@echo -e: "$(RED)object files deleted!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo -e: "$(RED)$(NAME) deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re norminette