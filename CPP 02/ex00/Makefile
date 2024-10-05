# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 13:53:09 by yboutsli          #+#    #+#              #
#    Updated: 2024/10/03 19:45:21 by yboutsli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCE_FILES = Fixed.cpp main.cpp 
OBJECT_FILES = $(addprefix object_files/,$(SOURCE_FILES:.cpp=.o)) 

RM = rm -rf

NAME = Fixed 

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)
	
object_files/%.o: %.cpp
	mkdir -p object_files
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) object_files

fclean: clean
	$(RM) $(NAME) 

re: fclean all