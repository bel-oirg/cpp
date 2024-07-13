NAME = Interface
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
SRCS = AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

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