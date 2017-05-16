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

SOURCE = 	ft_itoa_base.c ft_parse_param.c \
		ft_print_char.c ft_print_double.c \
		ft_print_float.c ft_print_int.c ft_print_ptr.c \
		ft_print_string.c ft_print_with_params.c \
		ft_printf.c ft_ftoa_base.c 


OBJECTS = $(SOURCE:.c=.o)

LIB_DIR = ./libft/

LIB_INC = ./libft/libft.h

HEAD = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB_DIR)libft.a
	ar rc $(NAME) $(OBJECTS) $(LIB_DIR)*.o
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(LIB_DIR) -I $(LIB_INC) -I $(HEAD)

$(LIB_DIR)libft.a:
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all