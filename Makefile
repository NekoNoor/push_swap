# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/04 15:05:19 by nschat        #+#    #+#                  #
#    Updated: 2021/08/04 15:38:42 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc

IDIR = include
CFLAGS = -Wall -Wextra -Werror -I $(IDIR)

SRC = src/main.c
OBJ = $(SRC:.c=.o)

HEADERS = push_swap.h

NAME = push_swap

vpath %.h include

all: $(NAME)

$(NAME): $(HEADERS) | $(OBJ)
	$(CC) $(CFLAGS) $| -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all
