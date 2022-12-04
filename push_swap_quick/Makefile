PUSH_SWAP =		push_swap
CHECKER =		checker
NAME =			$(PUSH_SWAP) $(CHECKER)
LIBFT_A =		libftprintf.a

COMP =			cc -Wall -Werror -Wextra -I includes -I libft/srcs -I libft/libs/libft -c -o

OBJ_DIR =		obj/
# S_SRC_DIR =		srcs/shared/
P_SRC_DIR =		srcs/push_swap/
C_SRC_DIR =		srcs/checker/
LIBFT =			libft/

# S_SRC =			create_frame.c \
# 				display_stacks.c \
# 				do_pa.c \
# 				do_pb.c \
# 				do_ra.c \
# 				do_rb.c \
# 				do_rr.c \
# 				do_rra.c \
# 				do_rrb.c \
# 				do_rrr.c \
# 				do_sa.c \
# 				do_sb.c \
# 				do_ss.c \
# 				fill_stack_a.c \
# 				push_swap_error.c \
# 				push_swap_free.c \
# 				stack_add_end.c \
# 				stack_add_top.c \
# 				stack_del_top.c

P_SRC =			main.c

C_SRC =			checker.c \
				do_launch.c \
				sort_test.c

# S_OBJ =			$(S_SRC:%.c=%.o)
P_OBJ =			$(P_SRC:%.c=%.o)
# C_OBJ =			$(C_SRC:%.c=%.o)
OBJ =			$(S_OBJ) $(P_OBJ) $(C_OBJ)

# S_SRC_PATH =   	$(S_SRC:%=$(S_SRC_DIR)%)
P_SRC_PATH =   	$(P_SRC:%=$(P_SRC_DIR)%)
# C_SRC_PATH =   	$(C_SRC:%=$(C_SRC_DIR)%)
# SRC_PATH =		$(S_SRC_PATH) $(P_SRC_PATH) $(C_SRC_PATH)

# S_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(S_OBJ))
P_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(P_OBJ))
# C_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(C_OBJ))
# OBJ_PATH =		$(S_OBJ_PATH) $(P_OBJ_PATH) $(C_OBJ_PATH)
OBJ_PATH =		$(P_OBJ_PATH)

RESET_COLOR =	\033[0m

all:			color do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n\033[32;1m PUSH_SWAP AND CHECKER COMPLETE $(RESET_COLOR) \\n"

$(OBJ_DIR):
				@kdir -p $(OBJ_DIR)
				@cho Create: Object directory

$(NAME):		$(OBJ_PATH)
				@cc $(P_OBJ_PATH) *.a -o push_swap \
					-I includes -I libft/includes
#				cc $(S_OBJ_PATH) $(P_OBJ_PATH) *.a -o push_swap \
					-I includes -I libft/includes
#				cc $(S_OBJ_PATH) $(C_OBJ_PATH) *.a -o checker \
					-I includes -I libft/includes

# $(S_OBJ_PATH):	$(S_SRC_PATH)
# 				$(MAKE) $(S_OBJ)

$(P_OBJ_PATH):	$(P_SRC_PATH)
				$(MAKE) $(P_OBJ)

# $(C_OBJ_PATH):	$(C_SRC_PATH)
# 				$(MAKE) $(C_OBJ)

# $(S_OBJ):		$(LIBFT_A)
# 				echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
# 				$(COMP) $(OBJ_DIR)$@ $(S_SRC_DIR)$(@:%.o=%.c)
# $(C_OBJ):		$(LIBFT_A)
# 				echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
# 				$(COMP) $(OBJ_DIR)$@ $(C_SRC_DIR)$(@:%.o=%.c)
$(P_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(P_SRC_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)
				@cp $(LIBFT)/$(LIBFT_A) .

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
				make -C $(LIBFT) clean
				echo "\\n\033[32;1m Cleaned libft object files $(RESET_COLOR)"

fclean:			clean
				/bin/rm -f $(PUSH_SWAP) $(CHECKER) $(LIBFT_A)
				make -C $(LIBFT) fclean
				echo "\\n\033[32;1m Cleaned $(NAME) $(RESET_COLOR) \\n"

re: 			fclean all

.PHONY:			all clean flcean re color