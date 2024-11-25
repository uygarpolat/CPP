# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 18:56:41 by upolat            #+#    #+#              #
#    Updated: 2024/11/26 01:13:35 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = amateria
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23

SOURCES = 	main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp \
			ICharacter.cpp IMateriaSource.cpp MateriaSource.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean:
	rm -f $(OBJECTS) $(NAME)

.PHONY: all fclean