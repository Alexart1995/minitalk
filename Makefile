# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 19:55:15 by snuts             #+#    #+#              #
#    Updated: 2021/11/25 20:35:52 by snuts            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS	=	server.c
SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)
SERVER_NAME	=	server

CLIENT_SRCS	=	client.c
CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)
CLIENT_NAME	=	client

SERVER_SRCS_BONUS	=	server_bonus.c
SERVER_OBJS_BONUS	=	$(SERVER_SRCS_BONUS:.c=.o)
SERVER_NAME_BONUS	=	server_bonus

CLIENT_SRCS_BONUS	=	client_bonus.c
CLIENT_OBJS_BONUS	=	$(CLIENT_SRCS_BONUS:.c=.o)
CLIENT_NAME_BONUS	=	client_bonus

NAME		=	minitalk
NAME_BONUS		=	minitalk_bonus
RM		=	rm -f
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror

$(NAME)		:	$(SERVER_NAME) $(CLIENT_NAME)

$(NAME_BONUS) :	$(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

$(SERVER_NAME)	:	$(SERVER_OBJS)
			$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_NAME)	:	$(CLIENT_OBJS)
			$(CC) $(CFLAGS) $^ -o $@

$(SERVER_NAME_BONUS)	:	$(SERVER_OBJS_BONUS)
			$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_NAME_BONUS)	:	$(CLIENT_OBJS_BONUS)
			$(CC) $(CFLAGS) $^ -o $@

all		:	$(NAME) $(NAME_BONUS)

clean		:
			$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

fclean		:	clean
			$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re		:	fclean all

bonus		:	$(NAME_BONUS)

.PHONY		:	all clean fclean re bonus