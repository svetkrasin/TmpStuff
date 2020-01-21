# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 07:46:44 by skrasin           #+#    #+#              #
#    Updated: 2019/07/28 23:41:51 by skrasin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = work_eval.c work_with_steck.c work_with_str.c evalexpr.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

.PHONY: clean
clean:
	rm -f *.o

.PHONY: all
all: $(NAME)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
