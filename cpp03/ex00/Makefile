# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 00:31:20 by upolat            #+#    #+#              #
#    Updated: 2024/11/23 01:15:36 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23

SOURCES = main.cpp ClapTrap.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean:
	rm -f $(OBJECTS) $(NAME)

.PHONY: all fclean