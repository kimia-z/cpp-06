NAME = converter

CFLAGS = -Wall -Wextra -Werror

CPP = c++

SRC = main.cpp ScalarConverter.cpp TypeDetector.cpp

NAME = convert


OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re