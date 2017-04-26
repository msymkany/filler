#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 15:13:54 by msymkany          #+#    #+#              #
#    Updated: 2017/04/17 15:14:07 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FIL_I = ./includes/filler.h
INCLUDES = -I $(FIL_I)

SOURCE = filler.c \
            clean_struct.c \
            read_input.c \
            place_on_map.c \
            manage_distance_map.c \

OBJECTS = $(SOURCE:.c=.o)

# libraries
LIBFT_DIR = ./libft/

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_DIR)libft.a
		$(CC) $(FL) $(OBJECTS) -o $(NAME) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(FL) -c $< -o $@

$(LIBFT_DIR)libft.a:
		make -C $(LIBFT_DIR)

.PHONY: clean fclean re

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all