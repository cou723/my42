NAME = libftprintf.a
INCLUDE = libft
LIBFT_DIR = libs/libft/
LIBFT_FILES = ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c
SRC_DIR = srcs/
SRC_FILES = puts.c putnbrs.c ft_printf.c
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILES))
SRCS = $(LIBFT) $(addprefix $(SRC_DIR), $(SRC_FILES))
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME) test.c
	$(CC) -g3 test.c libftprintf.a -o test
	bash ./test.sh


debug: test
	gdb ./test

.PHONY: all clean fclean re test
