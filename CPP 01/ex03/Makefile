# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 10:48:39 by yboutsli          #+#    #+#              #
#    Updated: 2024/09/19 15:26:05 by yboutsli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 

OBJ_DIR		=	obj/

SOURCE_FILES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJECT_FILES = $(addprefix $(OBJ_DIR),$(SOURCE_FILES:.cpp=.o))

RM = rm -rf

NAME = ex03 

all: $(NAME)

$(NAME): $(OBJECT_FILES) 
	$(CC) $(CPPFLAGS) $^ -o $@
	
$(OBJ_DIR)%.o: %.cpp HumanA.hpp HumanB.hpp Weapon.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all