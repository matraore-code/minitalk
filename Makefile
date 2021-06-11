# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matraore <matraore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 05:15:16 by matraore          #+#    #+#              #
#    Updated: 2021/06/09 13:08:37 by matraore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER =  server
CLIENT = client
CC = gcc
FLAGS = -Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o tools2.o tools.o includes/minitalk.h includes/tools.h
	@$(CC) server.o tools2.o tools.o  -o $@

$(CLIENT) : client.o tools2.o tools.o includes/minitalk.h includes/tools.h
	@$(CC) client.o tools2.o tools.o -o $@

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@rm -f *.o

fclean: clean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all