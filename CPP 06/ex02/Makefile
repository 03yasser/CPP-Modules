CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCE_FILES =  main.cpp Base.cpp main.cpp
HEADER_FILES = Base.hpp A.hpp B.hpp C.hpp
OBJECT_FILES = $(addprefix object_files/,$(SOURCE_FILES:.cpp=.o)) 

RM = rm -rf

NAME = ex02

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)
	
object_files/%.o: %.cpp  $(HEADER_FILES)
	mkdir -p object_files
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) object_files

fclean: clean
	$(RM) $(NAME)

re: fclean all