# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 16:07:53 by upolat            #+#    #+#              #
#    Updated: 2024/08/16 21:20:52 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SOURCES = megaphone.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(NAME)

.PHONY: all clean
