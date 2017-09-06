# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esterna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 17:01:46 by esterna           #+#    #+#              #
#    Updated: 2017/09/05 19:13:09 by esterna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor
CFLAGS = -Wall -Wextra -Werror
DEPS = libftprintf.a\
	   libft.a
FUNCTIONS =	check_form.c\
			find_coeffs.c\
			print_reduced.c\
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
