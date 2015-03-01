#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/16 11:53:26 by igomez            #+#    #+#              #
#    Updated: 2015/02/28 08:26:55 by igomez           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= game_2048

SRC			= $(shell find "sources" -type f -print | grep "\.c")

OBJ			= $(SRC:.c=.o)
CC			= /usr/bin/gcc
CFLAGS		= -Wall -Wextra -Werror -I ./includes/
CDEBUG		= -Wall -Wextra -Werror -I ./includes/
RM			= /bin/rm -f
ECHO		= /bin/echo -e

$(NAME)	:	$(OBJ)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lncurses
			@$(ECHO) '> Compiled'

clean	:
			-@$(RM) $(OBJ)
			@$(ECHO) '> Directory cleaned'

all		:	$(NAME)

fclean	:	clean
			-@$(RM) $(NAME) -lncurses
			@$(ECHO) '> Remove executable'

re		:	fclean all

.PHONY	:	all clean re

.c.o	:
			$(CC) $(CFLAGS) -o $@ -c $<
