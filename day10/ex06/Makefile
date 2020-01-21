# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 21:30:08 by skrasin           #+#    #+#              #
#    Updated: 2019/07/23 17:18:00 by skrasin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_d.c
OBJECTS = $(SOURCES:.c=.o)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) $(SOURCES)

clean:
	@rm -f $(NAME)

all: $(NAME)

re: clean all
