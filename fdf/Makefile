# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvillat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/02 11:37:57 by gvillat           #+#    #+#              #
#    Updated: 2016/06/02 11:38:01 by gvillat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = fdf

SOURCES =	main.c\
			parsing.c\
			tracing.c\
			projection.c\
			events.c\
			errors.c

HEADERS = fdf.h

OBJECT = $(SOURCES:.c=.o)

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

$(NAME):
	@make --directory libft/
	@$(CC) $(FLAGS) -o fdf libft/libft.a $(SOURCES) $(FRAMEWORK)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@make clean --directory libft/
	@echo "\033[1;34mFDF\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean --directory libft/
	@echo "\033[1;34mFDF\t\033[1;33mCleaning\t\033[0;32m[OK]\033[0m"

re: fclean all

rr:
	$(CC) $(FLAGS) -o fdf libft/libft.a $(SOURCES) $(FRAMEWORK)

run:
	./$(NAME)

.PHONY: clean fclean
