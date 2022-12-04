PROGRAM := a.out
CC := gcc
CFLAG := -Wall -Wextra -Werror
SRCDIR := ./src
OBJDIR := $(SRCDIR)
SRCS := $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_strcmp.c $(SRCDIR)/ft_strlen.c
OBJS := $(SRCS:%.c=%.o)
TARGET := ./$(PROGRAM)
LIB := ./libft.a

debug: ./debug

./debug: ft_split.debug.c main.c
	$(CC) $(CFLAG) ft_split.debug.c main.c -o ./$@

all: ft_split.c main.c
	$(CC) $(CFLAG) ft_split.c main.c

clean:
	rm $(OBJS)

fclean: clean
	rm $(LIB)

re: fclean all
