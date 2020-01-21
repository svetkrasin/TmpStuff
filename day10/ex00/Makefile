# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 14:11:25 by skrasin           #+#    #+#              #
#    Updated: 2019/07/23 14:08:53 by skrasin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs
SOURCES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c \
			srcs/ft_strlen.c srcs/ft_swap.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I./includes/

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)
