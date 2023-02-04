NAME     = ex00
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS     = main.cpp Bureaucrat.cpp
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

.PHONY : all fclean re
