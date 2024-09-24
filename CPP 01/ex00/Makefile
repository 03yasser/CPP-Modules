# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 10:23:12 by yboutsli          #+#    #+#              #
#    Updated: 2024/09/24 18:47:04 by yboutsli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 

OBJ_DIR		=	obj/

SOURCE_FILES = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJECT_FILES = $(addprefix $(OBJ_DIR),$(SOURCE_FILES:.cpp=.o))

RM = rm -rf

NAME = Zombie

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CPPFLAGS) $^ -o $@
	
$(OBJ_DIR)%.o: %.cpp Zombie.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all