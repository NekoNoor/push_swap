# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 17:30:18 by nschat        #+#    #+#                  #
#    Updated: 2021/09/02 16:22:17 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC := gcc

IDIR := include
CFLAGS ?= -Wall -Wextra -Werror -I $(IDIR)

ifeq (1,${DEBUG})
	CFLAGS := $(CFLAGS) -g
endif

ODIR := obj
SRC := ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_islower.c \
	  ft_isprint.c \
	  ft_isspace.c \
	  ft_isupper.c \
	  ft_itoa.c \
	  ft_lstadd_back.c \
	  ft_lstadd_front.c \
	  ft_lstclear.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstlast.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_lstsize.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strrev.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c
OBJ := $(addprefix $(ODIR)/,$(SRC:.c=.o))

HEADERS := libft.h
NAME := libft.a

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
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all
