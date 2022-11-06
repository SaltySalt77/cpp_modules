# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 15:40:24 by hyna              #+#    #+#              #
#    Updated: 2022/11/06 16:46:58 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
CCFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = megaphone.cpp\

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