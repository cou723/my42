PROGRAM := a.out
CC := gcc
CFLAG := -Wall -Wextra -Werror
SRCDIR := ./srcs
INCLUDE = -I./includes
OBJDIR := $(SRCDIR)
SRCS := $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_strcmp.c $(SRCDIR)/ft_strlen.c
OBJS := $(SRCS:%.c=%.o)
TARGET := ./$(PROGRAM)
LIB := ./libft.a

all: $(OBJS) $(LIB)

$(OBJS): $(SRCS)
	$(CC) $(INCLUDE) $(CFLAG) -c $(@:%.o=%.c) -o ./$@

$(LIB): $(OBJS)
	ar r $(LIB) $(OBJS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(LIB)

re: fclean all
