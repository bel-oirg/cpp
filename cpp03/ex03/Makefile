NAME = DiamonTrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp DiamonTrap.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamonTrap.hpp

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