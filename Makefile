# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alao <alao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 15:45:38 by alao              #+#    #+#              #
#    Updated: 2016/10/29 07:29:57 by alao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

N_INC = minishell.h

N_SRCS +=	minishell.c					\
			core/memory.c				\
			core/signal.c				\
			core/fork_simple.c			\
			core/path_solver.c

N_SRCS +=	terminal/tc_welcome.c		\
			terminal/tc_init.c			\
			terminal/tc_parser.c		\
			terminal/tc_hooker.c

N_SRCS +=	builtins/builtins.c			\
			builtins/bi_cd.c			\
			builtins/bi_env_core.c		\
			builtins/bi_env_opt.c		\
			builtins/bi_env.c			\
			builtins/bi_unsetenv.c		\
			builtins/bi_setenv.c		\
			builtins/bi_echo.c

N_SRCS +=	history/history.c

N_SRCS +=	completion/completion.c		\
			completion/c_parser.c		\
			completion/c_matching.c		\
			completion/c_terminal.c		\
			completion/c_printer.c		\
			completion/c_clearing.c

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -g

P_ADD = core/ completion/ builtins/ history/ terminal/
P_SRCS = ./srcs/
P_OBJ = ./obj/
P_LFT = libft/

I_INC = ./includes
I_LFT = ./libft/includes
I_ADD = -ltermcap
L_LFT = -L./libft/ -lft

NOC=\033[0m
OKC=\033[32;05m
ERC=\033[31m
WAC=\033[33m

ADD = $(addprefix $(P_OBJ),$(P_ADD))
SRC = $(addprefix $(P_SRCS),$(N_SRCS))
OBJ = $(addprefix $(P_OBJ),$(OBJ_NAME))
INC = $(addprefix -I,$(I_INC) $(I_LFT))

OBJ_NAME = $(N_SRCS:.c=.o)

all: $(NAME)

project: clean proj

proj: $(OBJ)
	@$(CC) $(CC_FLAGS) $(I_ADD) -o $(NAME) $(OBJ) $(INC) $(L_LFT)
	@echo "$(OKC)$(NAME): compilation success!$(NOC)"

$(NAME): $(OBJ)
	@make -C $(P_LFT)
	@$(CC) $(CC_FLAGS) $(I_ADD) -o $(NAME) $(OBJ) $(INC) $(L_LFT)
	@echo "$(OKC)$(NAME): compilation success!$(NOC)"

$(P_OBJ)%.o: $(P_SRCS)%.c
	@echo "$(OKC)\c"
	@mkdir -p $(P_OBJ) $(ADD)
	@$(CC) $(CC_FLAGS) -o $@ -c $^ $(INC)
	@echo -n █
	@echo "$(NOC)\c"

clean:
	@make -C $(P_LFT) clean
	@rm -rf $(P_OBJ)
	@echo "$(WAC)$(NAME): Removing $(NAME) ./obj/$(NOC)"

fclean: clean
	@make -C $(P_LFT) fclean
	@rm -f $(NAME)
	@echo "$(WAC)$(NAME): Removing executable$(NOC)"

re: fclean all
