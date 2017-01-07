CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = fractol

SOURCES =	main.c\
					images.c\
					fractals.c\
					mandelbrot.c

HEADERS = fractol.h

OBJECT = $(SOURCES:.c=.o)

$(NAME):
	@make --directory libft/
	@$(CC) $(FLAGS) -o fractol libft/libft.a $(SOURCES) $(FRAMEWORK)

FRAMEWORK = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@make clean --directory libft/
	@echo "\033[1;34mFractol\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean --directory libft/
	@echo "\033[1;34mFractol\t\t\033[1;33mCleaning\t\033[0;32m[OK]\033[0m"

re: fclean all

rr:
	$(CC) $(FLAGS) -o fractol libft/libft.a $(SOURCES) $(FRAMEWORK)

run:
	./$(NAME)

.PHONY: clean fclean
