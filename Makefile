# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/04 15:05:19 by nschat        #+#    #+#                  #
#    Updated: 2021/09/08 13:11:27 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC := gcc

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

IDIR := include
LDFLAGS ?= -L libft -lft
CFLAGS ?= -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT_DIR)/include

ifeq (1,${DEBUG})
	CFLAGS := $(CFLAGS) -g
	LDFLAGS := $(LDFLAGS) -g
endif

ODIR := obj
SRC := main.c \
	   input.c
OBJ := $(addprefix $(ODIR)/,$(SRC:.c=.o))

HEADERS := push_swap.h
NAME := push_swap

vpath %.c src
vpath %.h $(IDIR)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) | $(OBJ)
	$(CC) $(LDFLAGS) $| -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(ODIR)/%.o: $(ODIR) $(HEADERS) | %.c
	$(CC) $(CFLAGS) -c $| -o $@

$(ODIR):
	mkdir -p $@

clean:
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
