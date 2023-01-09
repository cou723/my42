NAME = 		cub3D
LIBS = 		-Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_DIR =	libft/
LIBFT_A =	$(LIBFT_DIR)libft.a

SRC = 	main.c \
		raycaster.c \
		draw_line.c \
		init_ray.c \
		key_hooks.c \
		check_map_error.c \
		update_player.c \
		read_config.c \
		read_map.c \
		init_game.c \
		init_config.c \
		init_map.c \
		init_player.c \
		wrap_open.c \
		wrap_calloc.c \
		utils.c \


VPATH = srcs:srcs/wlibc:srcs/cubfile:srcs/init:srcs/raycasting

OBJ_DIR = 	objs/
OBJ = 		$(SRC:%.c=%.o)
OBJ_PATH = 	$(addprefix $(OBJ_DIR),$(SRC:.c=.o))

INCLUDE = 	-Ilibft/ -Ignl/ -Iincludes/ -I/usr/include -Imlx_linux
FLAG = 		-Werror -Wextra -Wall -g3

all :  do_libft mlx $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_PATH)
	# sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
	$(CC) $(FLAG) $(OBJ_PATH) $(LIBFT_A) $(INCLUDE) $(LIBS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

mlx:
	make -C ./mlx_linux

clean:
	rm -rf objs
	make clean -C ./mlx_linux
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all
	make -C ./mlx_linux re

do_libft:
	make -C $(LIBFT_DIR)

norm:
	norminette srcs/*/*.c srcs/*.c libft/*.c libft/*.h includes/*.h

error_case: all
	./error_case.sh 2>&1 |  grep -v ignored

.PHONY: all clean fclean re do_gnl do_libft mlx
