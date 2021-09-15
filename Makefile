# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/04 15:05:19 by nschat        #+#    #+#                  #
#    Updated: 2021/09/15 15:40:51 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC := gcc

LIB_DIR := lib

LIBFT_DIR := $(LIB_DIR)/libft
LIBFT := $(LIBFT_DIR)/libft.a

LIBGNL_DIR := $(LIB_DIR)/libgnl
LIBGNL := $(LIBGNL_DIR)/libgnl.a

IDIR := include

LDFLAGS ?= -L $(LIBFT_DIR) -L $(LIBGNL_DIR) -lft -lgnl
CFLAGS ?= -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT_DIR)/$(IDIR) -I $(LIBGNL_DIR)/$(IDIR)

ifeq (1,${DEBUG})
	CFLAGS := $(CFLAGS) -g
	LDFLAGS := $(LDFLAGS) -g
endif

ODIR := obj

SRC := error.c \
	   input.c
OBJ := $(addprefix $(ODIR)/,$(SRC:.c=.o))

SRC_PUSH_SWAP_DIR = push_swap
SRC_PUSH_SWAP := main.c
SRC_PUSH_SWAP := $(addprefix $(SRC_PUSH_SWAP_DIR)/,$(SRC_PUSH_SWAP))
OBJ_PUSH_SWAP := $(addprefix $(ODIR)/,$(SRC_PUSH_SWAP:.c=.o))

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

$(NAME): $(LIBFT) $(LIBGNL) | $(OBJ) $(OBJ_PUSH_SWAP)
	$(CC) $(LDFLAGS) $| -o $@

$(NAME_CHECKER): $(LIBFT) $(LIBGNL) | $(OBJ) $(OBJ_CHECKER)
	$(CC) $(LDFLAGS) $| -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBGNL):
	$(MAKE) -C $(LIBGNL_DIR)

$(ODIR)/%.o: $(ODIR) $(ODIR)/$(SRC_DIR) $(ODIR)/$(SRC_CHECKER_DIR) $(HEADERS) | %.c
	$(CC) $(CFLAGS) -c $| -o $@

$(ODIR):
	mkdir -p $@

$(ODIR)/$(SRC_DIR):
	mkdir -p $@

$(ODIR)/$(SRC_CHECKER_DIR):
	mkdir -p $@

clean:
	$(RM) $(NAME) $(NAME_CHECKER)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(OBJ) $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
