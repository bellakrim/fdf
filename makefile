# ------------- #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 18:13:59 by abellakr          #+#    #+#              #
#    Updated: 2022/02/24 10:31:06 by abellakr         ###   ########.fr        #
#                                                                              #
# ------------- #

NAME = fdf

CC = gcc

CFlAGS = -Wall -Wextra -Werror

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit

SRC = main.c read_maps.c utils.c draw_map.c graphic.c check_all.c free_leaks.c \
	math_handling.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo " \
			──────────────────────────────────────────────\n\
			─██████████████─████████████───██████████████─\n\
			─██░░░░░░░░░░██─██░░░░░░░░████─██░░░░░░░░░░██─\n\
			─██░░██████████─██░░████░░░░██─██░░██████████─\n\
			─██░░██─────────██░░██──██░░██─██░░██─────────\n\
			─██░░██████████─██░░██──██░░██─██░░██████████─\n\
			─██░░░░░░░░░░██─██░░██──██░░██─██░░░░░░░░░░██─\n\
			─██░░██████████─██░░██──██░░██─██░░██████████─\n\
			─██░░██─────────██░░██──██░░██─██░░██─────────\n\
			─██░░██─────────██░░████░░░░██─██░░██─────────\n\
			─██░░██─────────██░░░░░░░░████─██░░██─────────\n\
			─██████─────────████████████───██████─────────\n\
			────────────────────────────────────────────── \n"
	@make -C ./libft
	@$(CC) $(CFlAGS) $(FRAMEWORKS) $(OBJ) ./libft/libft.a -o $(NAME) 
clean :
	@rm -rf $(OBJ) 
	@make clean -C ./libft
fclean : clean
	@rm -rf $(NAME) 
	@make fclean -C ./libft
re : fclean all 
	
.PHONY : clean fclean all re
