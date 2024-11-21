# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 14:28:00 by upolat            #+#    #+#              #
#    Updated: 2024/11/21 14:41:33 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23

SOURCES = main.cpp Fixed.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean:
	rm -f $(OBJECTS) $(NAME)

.PHONY: all fclean