# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 08:09:09 by skrasin           #+#    #+#              #
#    Updated: 2019/07/25 17:18:39 by skrasin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_cat.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

.PHONY: clean
clean:
	@rm -f $(OBJECTS)

.PHONY: all
all: $(NAME)

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re: clean all
