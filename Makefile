# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matraore <matraore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 05:15:16 by matraore          #+#    #+#              #
#    Updated: 2021/06/09 05:29:07 by matraore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER =  server
CLIENT = client
CC = gcc
FLAGS = -Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o ft_error.o tools.o includes/minitalk.h
	@$(CC) server.o ft_error.o -o

$(CLIENT) : client.o ft_error.o tools.o includes/minitalk.h
	@$(CC) client.o error.o  -o 

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@rm -f *.o

fclean: clean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all