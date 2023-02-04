NAME = ex02
FLAG = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
CC   = c++

all    : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAG) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAG) -I./ -c $< -o $@

clean  :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re     : fclean all

.PHONY : all fclean re
