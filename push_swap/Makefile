PUSH_SWAP =		push_swap
CHECKER =		checker
NAME =			$(PUSH_SWAP) $(CHECKER)
LIBFT_A =		libftprintf.a

COMP =			cc -Wall -Werror -Wextra -I includes -I libft/srcs -I libft/libs/libft -c -o

OBJ_DIR =		obj/
P_SRC_DIR =		srcs/push_swap/
LIBFT =			libft/

P_SRC =			main.c

P_OBJ =			$(P_SRC:%.c=%.o)
P_SRC_PATH =   	$(P_SRC:%=$(P_SRC_DIR)%)
P_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(P_OBJ))
OBJ_PATH =		$(P_OBJ_PATH)
RESET_COLOR =	\033[0m

all:			 do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n\033[32;1m PUSH_SWAP AND CHECKER COMPLETE $(RESET_COLOR) \\n"

$(OBJ_DIR):
				@kdir -p $(OBJ_DIR)
				@cho Create: Object directory

$(NAME):		$(OBJ_PATH)
				@cc $(P_OBJ_PATH) $(LIBFT_A) -o push_swap \
					-I includes -I libft/includes

$(P_OBJ_PATH):	$(P_SRC_PATH)
				$(MAKE) $(P_OBJ)

$(P_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(P_SRC_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)
				@cp $(LIBFT)/$(LIBFT_A) .

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:
				/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
				make -C $(LIBFT) clean
				echo "\\n\033[32;1m Cleaned libft object files $(RESET_COLOR)"

fclean:			clean
				/bin/rm -f $(PUSH_SWAP) $(CHECKER) $(LIBFT_A)
				make -C $(LIBFT) fclean
				echo "\\n\033[32;1m Cleaned $(NAME) $(RESET_COLOR) \\n"

re: 			fclean all

.PHONY:			all clean flcean re