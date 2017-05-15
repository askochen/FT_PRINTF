#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: askochen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 17:18:28 by askochen          #+#    #+#              #
#    Updated: 2016/12/09 14:37:04 by askochen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = libftprintf.a

CC = gcc

LIBFT = libft/libft.a

SRC = test.c ft_itoa_base.c ft_parse_param.c \
		ft_print_char.c ft_print_double.c \
		ft_print_float.c ft_print_int.c ft_print_ptr.c \
		ft_print_string.c ft_print_with_params.c \
		ft_printf.c ft_ftoa_base.c 

OBJ = $(SRC:.c=.o)

HEADERS = libft/libft.h ft_printf.h 

FLAGS = -Wall 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C libft/

libft_clean:
	make -C libft/ clean

libft_fclean:
	make -C libft/ fclean

clean: libft_clean
	rm -f $(OBJ) ft_printf.h.gch  *~

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all
