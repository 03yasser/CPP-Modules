# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 11:38:14 by yboutsli          #+#    #+#              #
#    Updated: 2024/09/24 19:00:27 by yboutsli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 

OBJ_DIR		=	obj/

SOURCE_FILES = main.cpp File.cpp
OBJECT_FILES = $(addprefix $(OBJ_DIR),$(SOURCE_FILES:.cpp=.o))

RM = rm -rf

NAME = ex04 

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CPPFLAGS) $^ -o $@
	
$(OBJ_DIR)%.o: %.cpp File.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all