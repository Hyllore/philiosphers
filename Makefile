# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 15:32:49 by droly             #+#    #+#              #
#    Updated: 2017/05/23 10:48:20 by droly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c \
	  ft_putchar.c \
	  ft_putstr.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@clang $(FLAGS) -c $(SRC)
	@clang $(OBJ) -o $(NAME)
	@echo "Compilation success."

clean:
	@rm -f $(OBJ)
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Target cleaned."

re: fclean all

.PHONY: all clean fclean re
