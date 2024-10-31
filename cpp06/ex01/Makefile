NAME = serializer
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Serializer.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADER = Serializer.hpp Data.hpp

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