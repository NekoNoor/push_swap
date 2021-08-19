# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/04 15:05:19 by nschat        #+#    #+#                  #
#    Updated: 2021/08/06 14:44:18 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


CC := gcc

IDIR := include
LDFLAGS ?=
CFLAGS ?= -Wall -Wextra -Werror -I $(IDIR)

ifeq (1,${DEBUG})
	CFLAGS := $(CFLAGS) -g
	LDFLAGS := $(LDFLAGS) -g
endif

ODIR := obj
SRC := main.c
OBJ := $(addprefix $(ODIR)/,$(SRC:.c=.o))

HEADERS := push_swap.h
NAME := push_swap

vpath %.c src
vpath %.h $(IDIR)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(ODIR)/%.o: $(ODIR) $(HEADERS) | %.c
	$(CC) $(CFLAGS) -c $| -o $@

$(ODIR):
	mkdir -p $@

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all
