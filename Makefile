# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 16:12:04 by pnuti             #+#    #+#              #
#    Updated: 2022/03/10 18:06:32 by pnuti            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT
FLAGS	= -Wall -Wextra -Werror
SRC		=	main.c init.c loop_hooks.c purge.c render.c inter.c utils.c		\
			parser.c parser2.c parser3.c vectors.c vectors2.c rotation.c	\
			rotation2.c	trigonometry.c generic_math.c rot_quater.c			\
			scene_translate.c scene_rotate.c cyl_utils.c
			
OBJ		= $(SRC:.c=.o)
LIBS	= -L libft/ -lft -L minilibx-linux/ -lmlx_Linux -lXext -lX11 -lm -lz

all : $(NAME)

$(NAME) : $(OBJ) complibs
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

complibs :
	cd libft && make -s --no-print-directory
	cd minilibx-linux && make -s --no-print-directory

clean : cleanlibs
	rm -f $(OBJ)

cleanlibs :
	cd libft && make clean
	cd minilibx-linux && make clean

fclean : clean
	rm -f $(NAME)
	cd libft && make fclean

re : fclean all


.PHONY: all clean fclean re