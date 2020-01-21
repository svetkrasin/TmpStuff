CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
SRCS = bsq_fast.c file.c main.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $@ -O3 $(OBJS)

clean:
	rm -f $(OBJS) $(NAME)

all: $(NAME)

.PHONY: clean