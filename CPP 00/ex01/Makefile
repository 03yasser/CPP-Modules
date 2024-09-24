# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 18:17:40 by yboutsli          #+#    #+#              #
#    Updated: 2024/09/20 17:58:16 by yboutsli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR		=	obj/
INC_DIR		=	include/

SOURCE_FILES = Contact.cpp PhoneBook.cpp main.cpp
OBJECT_FILES = $(addprefix $(OBJ_DIR),$(SOURCE_FILES:.cpp=.o))

RM = rm -rf

NAME = PhoneBook

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CPPFLAGS) $^ -o $@
	
$(OBJ_DIR)%.o: %.cpp ex01.h PhoneBook.hpp Contact.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all