# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esterna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 17:01:46 by esterna           #+#    #+#              #
#    Updated: 2017/08/29 16:08:21 by esterna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor
CFLAGS = -Wall -Wextra -Werror
DEPS = libftprintf.a\
	   libft.a
FUNCTIONS =	ft_atod.c\
			check_form.c\
			find_coeffs.c\
			computor.c

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -g -o computor $(FUNCTIONS) $(DEPS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM/

re: fclean all
