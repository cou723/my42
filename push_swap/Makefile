NAME =			push_swap
LIBFT_DIR =			libft/
LIBFT_A =		$(LIBFT_DIR)libftprintf.a
CC =			cc

FLAG = 		-Wall -Wextra -Werror -g3
INCLUDE =		-I includes -I libft/srcs -I libft/libft
COMP =			$(CC) $(FLAG) $(INCLUDE) -c -o

OBJ_DIR =		obj/
SRC_DIR =		srcs/push_swap/
TEST_DIR =		test/

SRC =	main.c \
		checker_args.c\
		utils.c \
		ft_atoli.c \
		args_check.c \
		duplicate.c \
		sort.c \
		sort_seven.c \
		init.c \
		stack_new.c \
		stack_clear.c \
		stack_rotate.c \
		stack_swap.c \
		stack_edit.c \
		stack_utils.c \
		stack_get.c \
		stack_put.c \
		stack_max.c \
		stack_min.c \
		stacks_do_push.c \
		stacks_do_swap.c \
		stacks_do_rotate.c \
		stacks_do_rev_rotate.c \
		stacks_utils.c \
		stacks_cmd.c \
		stacks_cmd_optimaze.c

OBJ =			$(SRC:%.c=%.o)

SRC_PATH =		$(SRC:%=$(SRC_DIR)%)

OBJ_PATH =		$(addprefix $(OBJ_DIR), $(OBJ))

all: do_libft $(NAME)
	echo "\\nPUSH_SWAP COMPLETE\\n"

$(NAME): $(OBJ_DIR) $(OBJ_PATH) includes/push_swap.h
	$(CC) $(OBJ_PATH) $(LIBFT_A) -o push_swap \
		-I includes -I libft/includes

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

do_libft:
	make -C $(LIBFT_DIR)

clean:
	/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
	make -C $(LIBFT_DIR) clean
	echo "\\nCleaned $(NAME) object files\\n"

fclean:			clean
	/bin/rm -f $(NAME) $(LIBFT_A)
	make -C $(LIBFT_DIR) fclean
	/bin/rm -f ./libftprintf.a
	echo "\\nCleaned $(NAME) \\n"

re: 			fclean all

.PHONY:			all clean flcean re color

norm:
	norminette libft/* srcs/* includes/push_swap.h

# unit-test(not working)

test: do_libft int_digit_test is_only_num_test ft_atoli_test can_atoi_test is_num_args_test exists_duplicate_args_test stack_test

TEST_SRC = 		utils.c \
				ft_atoli.c \
				args_check.c \
				duplicate.c \
				sort.c \
				sort_seven.c \
				init.c \
				stack_new.c \
				stack_clear.c \
				stack_rotate.c \
				stack_swap.c \
				stack_edit.c \
				stack_utils.c \
				stack_get.c \
				stack_put.c \
				stack_max.c \
				stack_min.c \
				stacks_do_push.c \
				stacks_do_swap.c \
				stacks_do_rotate.c \
				stacks_do_rev_rotate.c \
				stacks_utils.c \
				stacks_cmd.c \
				stacks_cmd_optimaze.c

TEST_OBJ =			$(TEST_SRC:%.c=%.o)
TEST_OBJ_PATH =		$(addprefix $(OBJ_DIR), $(TEST_OBJ))

int_digit_test: $(OBJ) $(TEST_DIR)int_digit_test.c $(OBJ_PATH)
	$(CC) $(INCLUDE) -c $(TEST_DIR)$@.c -o $(OBJ_DIR)$@.o
	$(CC) $(TEST_OBJ_PATH) $(LIBFT_A) $(TEST_DIR)$@.c -o $(TEST_DIR)$@ $(INCLUDE)
	$(TEST_DIR)$@
	rm $(TEST_DIR)$@

is_only_num_test: $(OBJ) $(TEST_DIR)is_only_num_test.c $(OBJ_PATH)
	$(CC) $(INCLUDE) -c $(TEST_DIR)$@.c -o $(OBJ_DIR)$@.o
	$(CC) $(TEST_OBJ_PATH) $(LIBFT_A) $(TEST_DIR)$@.c -o $(TEST_DIR)$@ $(INCLUDE)
	$(TEST_DIR)$@
	rm $(TEST_DIR)$@

ft_atoli_test: $(OBJ) $(TEST_DIR)ft_atoli_test.c $(OBJ_PATH)
	$(CC) $(INCLUDE) -c $(TEST_DIR)$@.c -o $(OBJ_DIR)$@.o
	$(CC) $(TEST_OBJ_PATH) $(LIBFT_A) $(TEST_DIR)$@.c -o $(TEST_DIR)$@ $(INCLUDE)
	$(TEST_DIR)$@
	rm $(TEST_DIR)$@

can_atoi_test: $(OBJ) $(TEST_DIR)can_atoi_test.c $(OBJ_PATH)
	$(CC) $(INCLUDE) -c $(TEST_DIR)$@.c -o $(OBJ_DIR)$@.o
	$(CC) $(TEST_OBJ_PATH) $(LIBFT_A) $(TEST_DIR)$@.c -o $(TEST_DIR)$@ $(INCLUDE)
	$(TEST_DIR)$@
	rm $(TEST_DIR)$@

is_num_args_test: $(OBJ) $(TEST_DIR)is_num_args_test.c $(OBJ_PATH)
	$(CC) $(INCLUDE) -c $(TEST_DIR)$@.c -o $(OBJ_DIR)$@.o
	$(CC) $(TEST_OBJ_PATH) $(LIBFT_A) $(TEST_DIR)$@.c -o $(TEST_DIR)$@ $(INCLUDE)
	$(TEST_DIR)$@
	rm $(TEST_DIR)$@

exists_duplicate_args_test: $(OBJ) $(TEST_DIR)exists_duplicate_args_test.c $(OBJ_PATH)
	$(CC) $(INCLUDE) -c $(TEST_DIR)$@.c -o $(OBJ_DIR)$@.o
	$(CC) $(TEST_OBJ_PATH) $(LIBFT_A) $(TEST_DIR)$@.c -o $(TEST_DIR)$@ $(INCLUDE)
	$(TEST_DIR)$@
	rm $(TEST_DIR)$@

stack_test: $(OBJ) $(TEST_DIR)stack_test.c $(OBJ_PATH)
	$(CC) $(INCLUDE) -c $(TEST_DIR)$@.c -o $(OBJ_DIR)$@.o
	$(CC) $(INCLUDE) -c $(TEST_DIR)stack_test_utils.c -o $(OBJ_DIR)stack_test_utils.o
	$(CC) $(TEST_DIR)$@.c $(TEST_OBJ_PATH) $(OBJ_DIR)stack_test_utils.o $(LIBFT_A) -o $(TEST_DIR)$@ $(INCLUDE) -g3
	valgrind --leak-check=full $(TEST_DIR)$@
	rm $(TEST_DIR)$@
