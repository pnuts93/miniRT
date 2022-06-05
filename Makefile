# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 11:54:55 by bkeskint          #+#    #+#              #
#    Updated: 2022/06/05 16:08:35 by bkeskint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT
FLAGS	= -Wall -Wextra -Werror
SRC_GEN		=	main.c init.c loop_hooks.c purge.c render.c utils.c				\
			parser.c parser2.c parser3.c vectors.c vectors2.c rotation.c	\
			rotation2.c	trigonometry.c generic_math.c rot_quater.c			\
			scene_translate.c scene_rotate.c get_rgb.c	get_rgb_shapes.c	\
			get_shape.c get_normal.c get_shadow.c init2.c keys.c tra_obj.c	\
			rot_obj.c red_obj.c keys2.c utils2.c
OBJ		= $(SRC:.c=.o)

DIR_INTER = intersect
SRC_INTER =	$(DIR_INTER)/circle.c $(DIR_INTER)/cylinder.c $(DIR_INTER)/plane.c

SRC		=	$(SRC_GEN) $(SRC_INTER)

LIBFT	= ./libft

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
MINILIBX = ./mlx

$(NAME): $(OBJ) complibs
	$(CC) $(OBJ) -g $(FLAGS) -L $(LIBFT) -lft -L $(MINILIBX) -lmlx -lXext -lX11 -lm -lz -o $(NAME)

endif

ifeq ($(UNAME), Darwin)
MINILIBX = ./mlx

%.o: %.c
		${CC} ${FLAGS} -Imlxmac -c $< -o ${<:.c=.o}

$(NAME): $(SRC) complibs
	$(CC) -Lmlx -L $(MINILIBX) -lmlx -framework OpenGL -framework AppKit -L /usr/X11/lib -lXext -lX11 -L $(LIBFT) -lft $(SRC) -o $(NAME)

endif

all : $(NAME)

complibs :
	cd $(LIBFT) && make -s --no-print-directory
	cd $(MINILIBX) && make -s --no-print-directory

clean : cleanlibs
	rm -f $(OBJ)

cleanlibs :
	cd libft && make clean
	cd $(MINILIBX) && make clean

fclean : clean
	rm -f $(NAME)
	cd libft && make fclean

re : fclean all


.PHONY: all clean fclean re