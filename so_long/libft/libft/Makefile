NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strchr.c ft_strrchr.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_tolower.c \
	ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_split.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c\
	ft_strcmp.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c $(SRCS)

CC     = gcc
CFLAGS = -Wall -Werror -Wextra

OBJ_DIR = objs/
OBJS    = $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))
BOBJS   = $(addprefix $(OBJ_DIR),$(BSRCS:.c=.o))

ifdef WITH_BONUS
OBJS += $(BOBJS)
endif

all: $(NAME)
	echo "\\nLIBFT COMPLETE\\n"

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	make $(NAME) WITH_BONUS=1

clean:
	rm -f $(BOBJS) $(OBJS)
	echo "\\nCleaned $(NAME) object files\\n"

fclean: clean
	rm -f $(NAME)
	echo "\\nCleaned $(NAME) \\n"

re: fclean all



so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(BSRCS)
	gcc -nostartfiles -shared -o libft.so $(BOBJS)

.PHONY: all bonus clean fclean re so
