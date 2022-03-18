#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 14:53:21 by acastano          #+#    #+#              #
#    Updated: 2022/03/18 15:08:53 by acastano         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = santorini

SRCS = main.c error.c state.c turn.c board.c check_functions.c print.c

HEADERS = ./libft/includes/

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/
	$(CC) $(CFLAGS) -c $(SRCS) -I $(HEADERS)
	$(CC) -o $(NAME) $(OBJ) -I $(HEADERS) -L libft/ -lft

clean:
	@make clean -C libft/
	/bin/rm -f $(OBJ) *.c~ *.h~

fclean: clean
	@make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
