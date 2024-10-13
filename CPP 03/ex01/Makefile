# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 07:42:32 by yboutsli          #+#    #+#              #
#    Updated: 2024/10/13 11:29:49 by yboutsli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCE_FILES = ClapTrap.cpp main.cpp ScavTrap.cpp
OBJECT_FILES = $(addprefix object_files/,$(SOURCE_FILES:.cpp=.o)) 

RM = rm -rf

NAME = ScavTrap

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)
	
object_files/%.o: %.cpp ClapTrap.hpp ScavTrap.hpp
	mkdir -p object_files
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) object_files

fclean: clean
	$(RM) $(NAME)

re: fclean all