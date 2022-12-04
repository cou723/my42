PROGRAM := do-op
CC := gcc
CFLAG := -Wall -Wextra -Werror
SRCS := ./ft_atoi.c ./ll_putnbr.c ./calc_module.c ./main.c ./arg_tests.c ./ft_strlen.c
TARGET := ./$(PROGRAM)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $@

clean:
	rm $(TARGET)

re: clean $(TARGET)
