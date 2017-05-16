# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 15:32:49 by droly             #+#    #+#              #
#    Updated: 2017/05/16 11:38:30 by droly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c

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
