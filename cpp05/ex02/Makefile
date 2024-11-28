# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 09:52:25 by upolat            #+#    #+#              #
#    Updated: 2024/11/28 13:15:16 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23

SOURCES = 	main.cpp Bureaucrat.cpp AForm.cpp \
			ShrubberyCreationForm.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean:
	rm -f $(OBJECTS) $(NAME)

.PHONY: all fclean