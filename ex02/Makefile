CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98
NAME = ex02
SRCS = main.cpp \
		Cat.cpp \
		Dog.cpp \
		AAnimal.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp
OBJS = $(SRCS:%cpp=%o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(SRCS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all