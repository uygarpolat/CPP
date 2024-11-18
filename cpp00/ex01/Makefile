# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 08:57:15 by upolat            #+#    #+#              #
#    Updated: 2024/11/18 08:57:50 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_awesome_phonebook
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23

SOURCES = main.cpp my_awesome_phonebook.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean:
	rm -f $(OBJECTS) $(NAME)

.PHONY: all fclean
