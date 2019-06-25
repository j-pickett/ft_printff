# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apickett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 17:37:28 by apickett          #+#    #+#              #
#    Updated: 2019/06/21 17:37:29 by apickett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC = libft/*.c srcs/*.c 

BINARIES = *.o

FLAGS = -Wall -Wextra -Werror

all :$(NAME)

$(NAME): libftprintf.h
	gcc $(FLAGS) -c $(SRC) -I libftprintf.h
	ar rc $(NAME) $(BINARIES)
	ranlib $(NAME)

clean:
	rm -f $(BINARIES)
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
