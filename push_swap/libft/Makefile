NAME = 			libftprintf.a

CC = cc
INCLUDE = 		-I libft/
CFLAGS = 		-Wall -Werror -Wextra

LIBFT_DIR = 	libft/
SRC_DIR = 		srcs/

SRC_FILES = 	puts.c putnbrs.c ft_printf.c
SRC = 			$(LIBFT) $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = 			$(SRC:.c=.o)

all: do_libft $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)libft.a
	@cp $(LIBFT_DIR)libft.a $(NAME)
	@ar r $(NAME) $(OBJ)
	@echo "\\nFT_PRINTF COMPLETE\\n"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


do_libft:
	@$(MAKE) bonus -C $(LIBFT_DIR)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "\\nCleaned $(NAME) object files\\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "\\nCleaned $(NAME)\\n"

re: fclean all

debug: test
	gdb ./test

.PHONY: all clean fclean re test
