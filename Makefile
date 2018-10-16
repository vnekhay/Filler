# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 15:37:28 by vnekhay           #+#    #+#              #
#    Updated: 2018/07/19 01:47:15 by vnekhay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vnekhay.filler

VISRCS =	src/visualsrc/mlx_additions.c \
			src/visualsrc/mlx_begin.c \
			src/visualsrc/mlx_draw.c \
			src/visualsrc/mlx_draw_adds.c \
			src/visualsrc/mlx_finish_display.c \

SRCS= 	src/main_actions.c \
		src/additions.c \
		src/reading.c \

OBJECTS = $(SRCS:.c=.o)

VIOBJECTS = $(VISRCS:.c=.o)

HEADER = inc

VINAME = SomeVisual

# COLORS
C_NO	=	"\033[00m"
C_OK	=	"\033[35m"
C_GOOD	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

# MESSAGE
SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft/
	gcc -Wall -Wextra -Werror $(OBJECTS) -Iinc -Llibft -lft -o $(NAME)
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

%.o: %.c $(HEADER)/filler.h
	@$(CC) -c -o $@ $< -I $(HEADER)
	@echo "Linking" [ $< ] $(OK)

clean:
	make -C libft clean
	@rm -f $(OBJECTS)
	@rm -f $(VIOBJECTS)
	@echo "[Cleaning *.o]" $(OK)

fclean: clean
	make -C libft fclean
	@echo "Cleaning" [$(NAME)] "..." $(OK)
	@rm -f $(NAME)
	@rm -f $(VINAME)

re: fclean all

visual: $(VIOBJECTS)
	make -C libft/
	gcc -Wall -Wextra -Werror $(VIOBJECTS) -Iinc -Llibft -lft -o $(VINAME) -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re
