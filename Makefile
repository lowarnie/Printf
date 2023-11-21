# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowarnie <lowarnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 09:31:29 by lowarnie          #+#    #+#              #
#    Updated: 2023/11/20 10:37:07 by lowarnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
ALLFILES = ft_printf.c all_functions.c
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c all_functions.c

OBJ = $(SRC:.c=.o)
AR = ar rc

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) -o $@ $^

clean : 
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.phony: all clean fclean re