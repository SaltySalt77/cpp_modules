# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 15:40:24 by hyna              #+#    #+#              #
#    Updated: 2022/11/06 15:34:33 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
CCFLAGS = -Wall -Werror -Wextra

SRCS_NAME = megaphone.cpp\

SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.cpp=.obj)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

all : $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

$(OBJS_PATH)/%.obj : $(SRCS_PATH)/%.cpp
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf $(NAME)
re :
	$(MAKE) fclean
	$(MAKE) all


.PHONY: all clean fclean