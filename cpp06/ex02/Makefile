NAME = conv
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Base.cpp real_type.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADER = A.hpp B.hpp C.hpp Base.hpp real_type.hpp

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