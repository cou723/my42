PROGRAM := ft_display_file
CC := gcc
CFLAG := -Wall -Wextra -Werror
SRCDIR := .
SRCS := $(SRCDIR)/main.c
TARGET := ./$(PROGRAM)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAG) $(SRCS) -o $@

clean:
	rm $(TARGET)

fclean: clean
	rm $(TARGET)
