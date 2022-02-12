# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 16:12:04 by pnuti             #+#    #+#              #
#    Updated: 2022/02/12 11:32:13 by lhorefto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT
FLAGS	= -Wall -Wextra -Werror
SRC		= main.c init.c loop_hooks.c purge.c parser.c utils.c parser2.c
OBJ		= $(SRC:.c=.o)
LIBS	= -L libft/ -lft -L minilibx-linux/ -lmlx_Linux -lXext -lX11 -lm -lz

all : $(NAME)

$(NAME) : $(OBJ) ##complibs
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

complibs :
	cd libft && make -s --no-print-directory
	cd minilibx-linux && make -s --no-print-directory

clean : ##cleanlibs
	rm -f $(OBJ)

cleanlibs :
	cd libft && make clean
	cd minilibx-linux && make clean

fclean : clean
	rm -f $(NAME)
##	cd libft && make fclean
##	cd minilibx-linux && make fclean

re : fclean all


.PHONY: all clean fclean re