# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/04 15:05:19 by nschat        #+#    #+#                  #
#    Updated: 2021/08/04 15:53:37 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc

IDIR = include
CFLAGS = -Wall -Wextra -Werror -I $(IDIR)

ODIR = obj

SRC = main.c
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

HEADERS = push_swap.h

NAME = push_swap

vpath %.c src
vpath %.h $(IDIR)

all: $(NAME)

$(NAME): $(HEADERS) | $(OBJ)
	$(CC) $(CFLAGS) $| -o $@

$(ODIR)/%.o: $(ODIR) | %.c
	$(CC) $(CFLAGS) -c $| -o $@

$(ODIR):
	mkdir $@

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all
