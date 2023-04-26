NAME     = PmergeMe
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS     = main.cpp utils.cpp list_distance.cpp
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

re     : fclean all

test: CXXFLAGS = -std=c++98 -D TEST
test: re
	./test.sh

uni_test   :
	$(CXX) list_distance.cpp -std=c++11 -o test -D UNIT_TEST
	./test

.PHONY : all fclean re
