# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 11:19:43 by yboutsli          #+#    #+#              #
#    Updated: 2024/09/12 17:36:42 by yboutsli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR		=	obj/

SOURCE_FILES =	tests.cpp Account.cpp 
OBJECT_FILES = $(addprefix $(OBJ_DIR),$(SOURCE_FILES:.cpp=.o))

RM = rm -rf

NAME = Account

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CPPFLAGS) $^ -o $@
	
$(OBJ_DIR)%.o: %.cpp Account.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS)  -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all