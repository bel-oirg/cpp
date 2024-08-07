NAME = violence
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = HumanA.hpp HumanB.hpp Weapon.hpp

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS) : $(HEADER)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all

.PHONY: all clean fclean re