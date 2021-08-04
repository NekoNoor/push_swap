# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/04 15:05:19 by nschat        #+#    #+#                  #
#    Updated: 2021/08/04 15:17:50 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc

IDIR = include
CFLAGS = -Wall -Wextra -Werror -I $(IDIR)

SRC = src/main.c
OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)

%.o: $(IDIR)/header.h | %.c
	$(CC) $(CFLAGS) -c $| -o $@

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all
