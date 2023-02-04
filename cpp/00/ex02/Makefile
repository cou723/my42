NAME = phonebook
FLAG = -std=c++98 -Wall -Wextra -Werror
SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)
CC   = clang++

all    : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAG) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -I./ -c $< -o $@

clean  :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re     : fclean all

.PHONY : all fclean re
