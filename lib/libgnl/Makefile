# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/31 21:17:26 by nschat        #+#    #+#                  #
#    Updated: 2021/09/15 15:36:42 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC := gcc

IDIR := include
CFLAGS ?= -Wall -Wextra -Werror -I $(IDIR)

ifeq (1,${DEBUG})
	CFLAGS := $(CFLAGS) -g
endif

ODIR := obj
SRC := get_next_line.c \
	  get_next_line_utils.c
OBJ := $(addprefix $(ODIR)/,$(SRC:.c=.o))

HEADERS := get_next_line.h
NAME := libgnl.a

vpath %.c src
vpath %.h $(IDIR)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

$(ODIR)/%.o: $(ODIR) $(HEADERS) | %.c
	$(CC) $(CFLAGS) -c $| -o $@

$(ODIR):
	mkdir -p $@

clean:
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(NAME) test

re: fclean all
