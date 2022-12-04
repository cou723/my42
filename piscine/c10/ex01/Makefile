PROGRAM := ft_cat
CC := gcc
CFLAG := -Wall -Wextra -Werror
SRCDIR := .
SRCS := $(SRCDIR)/main.c $(SRCDIR)/ft_strcat.c
TARGET := ./$(PROGRAM)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAG) $(SRCS) -o $@

clean:
	rm $(TARGET)

fclean: clean
	rm $(TARGET)
