# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 19:12:52 by upolat            #+#    #+#              #
#    Updated: 2025/02/17 12:17:49 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -Wno-deprecated-declarations

SOURCES = tests.cpp Account.cpp

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
