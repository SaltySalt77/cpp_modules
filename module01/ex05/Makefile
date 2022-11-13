# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 15:40:24 by hyna              #+#    #+#              #
#    Updated: 2022/11/12 16:48:54 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl
CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Harl.cpp\

OBJS = $(SRCS:.cpp=.obj)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

%.obj : %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
re :
	@make fclean
	@make all


.PHONY: all clean fclean