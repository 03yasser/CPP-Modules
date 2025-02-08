CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCE_FILES =  main.cpp Bureaucrat.cpp Form.cpp
HEADER_FILES = Bureaucrat.hpp Form.hpp
OBJECT_FILES = $(addprefix object_files/,$(SOURCE_FILES:.cpp=.o)) 

RM = rm -rf

NAME = Form 

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