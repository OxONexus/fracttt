NAME = fractol

FLAGS = -g -Wextra

MLX_FLAG = -lmlx -framework OpenGL -framework AppKit -I. libft/libft.a

SRC =	init.c		\
		fractal.c	\
		hook_fct.c	\
		get_name.c	\
		image.c		\
		main.c		\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@echo "\n\033[33;32;7mCompiling $(NAME)\033[30;0;2m"
	gcc -g $(OBJ) -o $(NAME) $(FLAG) $(MLX_FLAG)

%.o:  %.c
	@echo "\033[33;31mMake :\033[30;0;2m $<"
	@gcc -g $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
