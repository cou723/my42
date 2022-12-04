NAME = 		so_long
LIBS = 		-Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_DIR =	libft/
LIBFT_A =	$(LIBFT_DIR)libftprintf.a

GNL_DIR = 	gnl/
GNL_A =  	$(GNL_DIR)get_next_line.a

SRC_DIR = 	srcs/
SRC = 		main.c game.c game_display.c game_event.c game_init.c game_move.c game_utils.c check_correct_args.c check_correct_map.c check_wall.c map_error.c error.c warning.c utils.c get_map_data.c
SRC_PATH = 	$(SRC:%=$(SRC_DIR)%)

OBJ_DIR = 	objs/
OBJ = 		$(SRC:%.c=%.o)
OBJ_PATH = 	$(addprefix $(OBJ_DIR),$(SRC:.c=.o))

INCLUDE = 	-Ilibft/ -Ilibft/srcs -Ilibft/libft -Iincludes/ -I/usr/include -Imlx_linux -Ignl/
FLAG = 		-Werror -Wextra -Wall

all :  do_libft do_gnl mlx $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_PATH) includes/so_long.h
	sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
	$(CC) $(FLAG) $(OBJ_PATH) $(LIBFT_A) $(GNL_A) $(INCLUDE) $(LIBS) -o $(NAME)

# $(%.o=srcs/%.c): $(SRC_PATH)
# 	$(CC) $(FLAG) $@ -c $< $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

mlx:
	make -C ./mlx_linux

clean:
	rm -rf objs
	make clean -C ./mlx_linux
	make clean -C ./libft
	make clean -C ./gnl

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
	make fclean -C ./gnl

re: fclean all
	make -C ./mlx_linux re

do_gnl:
	make -C $(GNL_DIR)

do_libft:
	make -C $(LIBFT_DIR)

test: all
	@echo "<<SAMPLE1>>"
	./so_long ./maps/sample1.ber
	@echo "<<SAMPLE2>>"
	./so_long ./maps/sample2.ber
	@echo "<<DUPLICATION_PLAYER>>"
	./so_long ./maps/error_maps/duplication_player.ber
	@echo "<<EMPTY>>"
	./so_long ./dummy.ber
	@echo "<<EMPTY_FILE>>"
	./so_long ./maps/error_maps/empty.ber
	./so_long ./maps/error_maps/empty_line.ber
	./so_long ./maps/error_maps/empty_first_line.ber
	./so_long ./maps/empty_end_line.ber
	@echo "<<INVALID_CHAR>>"
	./so_long ./maps/error_maps/invalid_char.ber
	@echo "<<NOT_EXIST_EXIT>>"
	./so_long ./maps/error_maps/not_exist_exit.ber
	@echo "<<NOT_EXIST_PLAYER>>"
	./so_long ./maps/error_maps/not_exist_player.ber
	@echo "<<NOT_EXIST_COLLECTIVE>>"
	./so_long ./maps/error_maps/not_exist_collective.ber
	@echo "<<NOT_RECT>>"
	./so_long ./maps/error_maps/not_rect.ber
	@echo "<<NOT_WALLED1>>"
	./so_long ./maps/error_maps/not_walled1.ber
	@echo "<<NOT_WALLED2>>"
	./so_long ./maps/error_maps/not_walled2.ber


testv: all
	@echo "<<SAMPLE1>>"
	-@valgrind --leak-check=full ./so_long ./maps/sample1.ber
	@echo "<<SAMPLE2>>"
	-@valgrind --leak-check=full ./so_long ./maps/sample2.ber
	@echo "<<DUPLICATION_PLAYER>>"
	-@valgrind --leak-check=full ./so_long ./maps/error_maps/duplication_player.ber
	@echo "<<EMPTY>>"
	-@valgrind --leak-check=full ./so_long ./maps/error_maps/empty.ber
	@echo "<<INVALID_CHAR>>"
	-@valgrind --leak-check=full ./so_long ./maps/error_maps/invalid_char.ber
	@echo "<<NOT_EXIST_EXIT>>"
	-@valgrind --leak-check=full ./so_long ./maps/error_maps/not_exist_exit.ber
	@echo "<<NOT_EXIST_PLAYER>>"
	-@valgrind --leak-check=full ./so_long ./maps/error_maps/not_exist_player.ber
	@echo "<<NOT_EXIST_COLLECTIVE>>"
	-@valgrind --leak-check=full ./so_long ./maps/error_maps/not_exist_collective.ber
	@echo "<<NOT_RECT>>"
	-@valgrind --leak-check=full ./so_long ./maps/error_maps/not_rect.ber
	@echo "<<NOT_WALLED1>>"
	-@valgrind --leak-check=full ./so_long ./maps/error_maps/not_walled1.ber
	@echo "<<NOT_WALLED2>>"
	-@valgrind --leak-check=full ./so_long ./maps/error_maps/not_walled2.ber

norm:
	norminette srcs/* includes/* libft/* gnl/*