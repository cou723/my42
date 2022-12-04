# names
SERVER        = server
CLIENT        = client
SERVER_B      = $(SERVER)_bonus
CLIENT_B      = $(CLIENT)_bonus

# dirs
MANDATORY_DIR = ./mandatory
BONUS_DIR     = ./bonus

# files
OBJ_S        = $(MANDATORY_DIR)/$(SERVER).o
OBJ_C        = $(MANDATORY_DIR)/$(CLIENT).o $(MANDATORY_DIR)/error_utils.o
OBJ_S_B      = $(BONUS_DIR)/$(SERVER)_bonus.o
OBJ_C_B      = $(BONUS_DIR)/$(CLIENT)_bonus.o $(BONUS_DIR)/error_utils_bonus.o
OBJ_COMMON   = $(MANDATORY_DIR)/minitalk_utils.o
OBJ_COMMON_B = $(BONUS_DIR)/minitalk_utils_bonus.o
HEADER       = $(MANDATORY_DIR)/minitalk
HEADER_B     = $(BONUS_DIR)/minitalk_bonus

# variables
CC       = gcc
FLAGS    = -Wall -Werror -Wextra
RESET    = \e[0m\n
GREEN    = \e[38;5;226m
YELLOW   = \e[38;5;46m
MAGENDA  = \e[38;5;206m
PURPLE   = \e[38;5;200m


all : $(SERVER) $(CLIENT)
bonus : $(SERVER_B) $(CLIENT_B)

$(SERVER) : $(OBJ_S) $(OBJ_COMMON) $(HEADER).h
	@$(CC) $(OBJ_S) $(OBJ_COMMON) -o $@
	@printf "$(GREEN)./$@ successfully build🥑$(RESET)"

$(CLIENT) : $(OBJ_C) $(OBJ_COMMON) $(HEADER).h
	@$(CC) $(OBJ_C) $(OBJ_COMMON) -o $@
	@printf "$(YELLOW)./$@ successfully build🥝$(RESET)"

$(SERVER_B) : $(OBJ_S_B) $(OBJ_COMMON_B) $(HEADER_B).h
	@$(CC) $(OBJ_S_B) $(OBJ_COMMON_B) -o $@
	@printf "$(GREEN)./$@ successfully build🥑$(RESET)"

$(CLIENT_B) : $(OBJ_C_B) $(OBJ_COMMON_B) $(HEADER_B).h
	@$(CC) $(OBJ_C_B) $(OBJ_COMMON_B) -o $@
	@printf "$(YELLOW)./$@ successfully build🥝$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

error_utils_bonus.c : error_utils.c
	@cp $(MANDATORY_DIR)/error_utils.c $(BONUS_DIR)/error_utils_bonus.c
	@sed -i "s/minitalk.h/minitalk_bonus.h/g" $(BONUS_DIR)error_utils_bonus.c

clean :
	@rm -f ./*/*.o
	@printf "$(MAGENDA).o files deleted🚽\e[0m\n"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@rm -f $(SERVER_B) $(CLIENT_B)
	@printf "$(PURPLE)Binaries deleted🗑\e[0m\n"

re: fclean all

fcleanm: clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "$(PURPLE)Mandatory binaries deleted🗑\e[0m\n"

fcleanb: clean
	@rm -f $(SERVER_B) $(CLIENT_B)
	@printf "$(PURPLE)Bonus binaries deleted🗑\e[0m\n"

m : $(SERVER) $(CLIENT)
b : $(SERVER_B) $(CLIENT_B)

rem: fcleanm m
reb: fcleanb b