NAME = philo

CC =		cc
FLAG =		-Wall -Werror -Wextra -g3 -pthread -fsanitize=thread
INCLUDE =	-I includes

SRC_DIR =	srcs/
SRC =		main.c \
			check_args.c \
			philo.c \
			philo_monitor.c \
			utils.c \
			init.c \
			eating.c \
			libft.c \
			destroy.c

SRC_PATH =	$(SRC:%=$(SRC_DIR)%)

OBJ_DIR =	obj/
OBJ =		$(SRC:.c=.o)
OBJ_PATH =	$(OBJ:%=$(OBJ_DIR)%)

all: $(NAME)
$(NAME): $(OBJ_DIR) $(OBJ_PATH)
	$(CC) $(FLAG) $(OBJ_PATH) -o $(NAME) $(INCLUDE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

nm: $(NAME)
	nm -u $(NAME) | grep -v  -e memset -e printf -e malloc -e free -e write -e usleep -e gettimeofday -e pthread_create -e pthread_detach -e pthread_join -e pthread_mutex_init -e pthread_mutex_destroy -e pthread_mutex_lock -e pthread_mutex_unlock

.PHONY: all clean fclean re
