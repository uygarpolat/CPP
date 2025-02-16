# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 08:57:15 by upolat            #+#    #+#              #
#    Updated: 2025/02/16 15:34:04 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_awesome_phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23

SOURCES = main.cpp my_awesome_phonebook.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
