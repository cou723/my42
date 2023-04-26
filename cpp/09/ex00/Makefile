NAME     = btc
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS     = main.cpp BitcoinExchange.cpp Date.cpp utils.cpp
OBJS     = $(SRCS:.cpp=.o)
CXX      = c++

all    : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I./ -c $< -o $@

clean  :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f ./test

re     : fclean all

test   : Date.cpp utils.cpp
	$(CXX) Date.cpp utils.cpp -std=c++11 -o test -D TEST
	./test

.PHONY : all fclean re
