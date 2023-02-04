NAME = megaphone
FLAG = -std=c++98 -Wall -Wextra -Werror

all    : $(NAME)

$(NAME): megaphone.cpp
	c++ megaphone.cpp $(FLAG)  -o megaphone

fclean :
	rm $(NAME)

re     : all fclean

.PHONY : all fclean re
