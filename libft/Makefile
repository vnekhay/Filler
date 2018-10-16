# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 15:37:28 by vnekhay           #+#    #+#              #
#    Updated: 2018/03/26 02:18:32 by vnekhay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc $(FLAGS)
FLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a
INCLUDES=	./inc
SRCS	=	src/ft_isdigit.c \
			src/ft_memset.c \
			src/ft_putnbr.c \
			src/ft_strchr.c \
			src/ft_strdup.c \
			src/ft_strjoin.c \
			src/ft_strlen.c \
			src/ft_strsub.c \
			src/ft_toupper.c \
			src/get_next_line.c \
			src/ft_strstr.c \
			src/ft_bzero.c \
			
OBJS	=	$(SRCS:.c=.o)

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

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

%.o: %.c $(INCLUDES)/libft.h
	@$(CC) -c -o $@ $< -I $(INCLUDES)
	@echo "Linking" [ $< ] $(OK)

clean:
	@rm -f $(OBJS)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
