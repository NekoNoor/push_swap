# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/04 15:05:19 by nschat        #+#    #+#                  #
#    Updated: 2021/09/15 13:39:05 by nschat        ########   odam.nl          #
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

SRC_DIR = push_swap
SRC := main.c \
	   input.c
SRC := $(addprefix $(SRC_DIR)/,$(SRC))
OBJ := $(addprefix $(ODIR)/,$(SRC:.c=.o))

SRC_CHECKER_DIR = checker
SRC_CHECKER := main.c
SRC_CHECKER := $(addprefix $(SRC_CHECKER_DIR)/,$(SRC_CHECKER))
OBJ_CHECKER := $(addprefix $(ODIR)/,$(SRC_CHECKER:.c=.o))

HEADERS := push_swap.h

NAME := push_swap
NAME_CHECKER := checker

vpath %.c src
vpath %.h $(IDIR)

.PHONY: clean fclean re

all: $(NAME) $(NAME_CHECKER)

$(NAME): $(LIBFT) | $(OBJ)
	$(CC) $(LDFLAGS) $| -o $@

$(NAME_CHECKER): $(LIBFT) | $(OBJ_CHECKER)
	$(CC) $(LDFLAGS) $| -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(ODIR)/%.o: $(ODIR) $(ODIR)/$(SRC_DIR) $(ODIR)/$(SRC_CHECKER_DIR) $(HEADERS) | %.c
	$(CC) $(CFLAGS) -c $| -o $@

$(ODIR):
	mkdir -p $@

$(ODIR)/$(SRC_DIR):
	mkdir -p $@

$(ODIR)/$(SRC_CHECKER_DIR):
	mkdir -p $@

clean:
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
