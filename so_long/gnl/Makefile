NAME = get_next_line.a
INCLUDE = include
SRCS = get_next_line.c get_next_line_utils.c
BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
LIB_DIR = lib
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)

ifdef WITH_BONUS
OBJS = $(BOBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus:
	@make $(NAME) WITH_BONUS=1

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -D BUFFER_SIZE=100 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bre: fclean bonus

test: test.c $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -D BUFFER_SIZE=1000000000001 -g test.c -o test

test-nf: test.c $(SRCS)
	$(CC) $(SRCS) -g test.c -o test

test-42: test.c $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -D BUFFER_SIZE=22 -g test.c -o test

norm:
	norminette $(SRCS)


.PHONY: all bonus clean fclean re bre
