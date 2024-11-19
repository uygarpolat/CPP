# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 19:12:52 by upolat            #+#    #+#              #
#    Updated: 2024/11/19 20:35:43 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -Wno-deprecated-declarations

SOURCES = tests.cpp Account.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean:
	rm -f $(OBJECTS) $(NAME)

.PHONY: all fclean
