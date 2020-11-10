# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwing <cwing@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 12:54:38 by cwing             #+#    #+#              #
#    Updated: 2020/05/14 14:31:14 by cwing            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = src/dir.c \
	src/flag.c \
	src/info.c \
	src/main.c \
	src/print.c \
	src/print2.c \
	src/s_dir.c \
	src/sort_list.c \
	src/utils.c \
	src/utils2.c 

INC = ./includes/
INC_FILE = $(INC)ft_ls.h
CC = gcc
FLAGS = -Wall -Wextra -Werror -I $(INC)
OBG = $(SRC:.c=.o)
LIBFT_PATH = ./libft/
LIBRA = $(LIBFT_PATH)libft.a

GREEN = \033[0;32;1m
RED = \033[0;31;1m
RESET = \033[0m

all: $(NAME)

%.o: %.c $(INC_FILE) 
	@printf "$(RED)[ft_ls] Compiling [...]\r"
	@$(CC) $(FLAGS) -c $< -o $@
	@printf "$(GREEN)[ft_ls] Compiling [!!!]\r$(RESET)"

$(NAME): $(OBG) $(LIBRA) 
	@$(CC) $(FLAGS) $(OBG) -o $(NAME) $(LIBRA)
	@printf "$(GREEN)[ft_ls] Compiled successfuly! [OK]$(RESET)\n"

$(LIBRA): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)

clean:
	@/bin/rm -f $(OBG)
	@make clean -C $(LIBFT_PATH)
	@printf "$(RED)[ft_ls] Removed object files!$(RESET)\n"

fclean: clean
	@make fclean -C $(LIBFT_PATH) 
	@rm -f $(NAME)
	@printf "$(RED)[ft_ls] Deleted successfuly! [OK]\n$(RESET)"

re: fclean all

mm:
	@$(MAKE) fclean
	@$(MAKE) all
	@$(MAKE) clean

.PHONY: all clean fclean re mm
