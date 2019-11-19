 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 15:53:53 by tebatsai          #+#    #+#              #
#    Updated: 2019/11/07 23:41:01 by tebatsai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tebatsai.filler

INCLUDES = -I$(HEADER_DIRECTORY) -I$(LIBFT_DIRECTORY)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADER_DIRECTORY = ./includes/
HEADER_LIST = ft_filler.h
HEADER = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SRCS_DIRECTORY = ./srcs/
SRCS_LIST = main.c play.c read_map.c lol.c maze.c placer.c
SRCS = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

OBJECTS_DIRECTORY = build/
OBJECT_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_LIST))



CC = gcc
FLAGS = -Wall -Werror -Wextra

BIBlack=\033[1;90m # Black
BIRed=\033[1;91m  # Red
BIGreen=\033[1;92m  # Green
BIYellow=\033[1;93m  # Yellow
BIBlue=\033[1;94m      # Blue
BIPurple=\033[1;95m  # Purple
BICyan=\033[1;96m       # Cyan
BIWhite=\033[1;97m  # White
BYellow= \033[1;33m  # Yellow
RESET = \033[0m

all:$(NAME)

$(NAME):$(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(OBJECTS) -o $(NAME) -g
	@echo "\n                 $(BIBlue)\t\t K å °ı° ™ $(RESET)\n"

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c $(HEADER)
	@$(CC) $(FLAGS) -g -c $(INCLUDES) $< -o $@ -g
	@echo "$(BIGreen) $(RESET)$(BIYellow)† $(RESET)\c"
	@echo "$(BIWhite)• $(RESET)$(BIPurple)◊ $(RESET)$(BIRed)∆ $(RESET)\c"

$(LIBFT):
	make -sC $(LIBFT_DIRECTORY)

norm:
	norminette $(SRCS) $(HEADER)
play1:
	@./resources/./filler_vm -p2 ./resources/players/superjeannot.filler -p1 ./tebatsai.filler -f ./resources/maps/map00
play2:
	@./resources/./filler_vm -p1 ./tebatsai.filler -p2 ./resources/players/superjeannot.filler -f ./resources/maps/map01
play3:
	@./resources/./filler_vm -p1 ./tebatsai.filler -p2 ./resources/players/superjeannot.filler -f ./resources/maps/map02
play4:
	@./resources/./filler_vm -p1 ./tebatsai.filler -p2 ./resources/players/superjeannot.filler -f ./resources/maps/map03
play5:
	@./resources/./filler_vm -f ./resources/maps/map00 -p1 ./tebatsai.filler

clean:
	@make -C $(LIBFT_DIRECTORY) clean
	@/bin/rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@/bin/rm -rf $(LIBFT)
	@/bin/rm -rf $(NAME)

re: fclean all
