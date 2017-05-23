#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: askochen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 13:10:46 by askochen          #+#    #+#              #
#    Updated: 2017/05/18 13:11:25 by askochen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS = -Wall 

SRC = 	ft_itoa_base.c ft_parse_param.c \
		tools.c ft_print_char.c ft_print_double.c \
		ft_print_int.c ft_print_int2.c ft_print_ptr.c \
		ft_print_string.c ft_print_with_params.c \
		ft_printf.c ft_ftoa_base.c ft_w_str_tools.c
		ft_w_char_tools.c


OBJ = $(SRC:.c=.o)

LIBFT = ./libft/

LIBFT_HEAD = ./libft/libft.h

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)libft.a
	ar rc $(NAME) $(OBJ) $(LIBFT)*.o
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I $(LIBFT) -I $(LIBFT_HEAD) -I $(HEADER)

$(LIBFT)libft.a:
	make -C $(LIBFT)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ) ft_printf.h.gch 

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
