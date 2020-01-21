CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
SRCS = ft.c bsq_next.c main.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $@ -O3 $(OBJS)

clean:
	rm -f main.o do-op

all: $(NAME)

.PHONY: clean