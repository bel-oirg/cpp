NAME = AMateria
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = AMateria.cpp Character.cpp MateriaSource.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = AMateria.hpp

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