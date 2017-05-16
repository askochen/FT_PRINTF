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

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_itoa_base.c ft_parse_param.c \
		ft_print_char.c ft_print_double.c \
		ft_print_float.c ft_print_int.c ft_print_ptr.c \
		ft_print_string.c ft_print_with_params.c \
		ft_printf.c ft_ftoa_base.c 


OBJ = $(SRC:.c=.o)

LIBFT = ./libft/

LIBFT_HEAD = ./libft/libft.h

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)libft.a
	ar rc $(NAME) $(OBJ) $(LIBFT)*.o
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(LIBFT) -I $(LIBFT_HEAD) -I $(HEADER)

$(LIBFT)libft.a:
	make -C $(LIBFT)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all