# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 09:52:25 by upolat            #+#    #+#              #
#    Updated: 2024/11/27 17:31:54 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23

SOURCES = 	main.cpp Bureaucrat.cpp Form.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean:
	rm -f $(OBJECTS) $(NAME)

.PHONY: all fclean