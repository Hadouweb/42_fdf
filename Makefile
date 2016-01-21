CC = gcc -Werror -Wextra -Wall -g -O0

SRCPATH = ./srcs
DRAWPATH = $(SRCPATH)/draw
READPATH = $(SRCPATH)/read
UTILPATH = $(SRCPATH)/util
HOOKPATH = $(SRCPATH)/hook
MATRIXPATH = $(SRCPATH)/matrix
INCPATH = ./includes

LIBFT = ./libft
MINILIBX = ./minilibx_macos

HEADER = -I $(LIBFT)/includes -I $(INCPATH) -I $(MINILIBX)

LIB = $(LIBFT)/libft.a $(MINILIBX)/libmlx.a -framework OpenGL -framework AppKit 

SRC = 	$(SRCPATH)/main.c\
		$(READPATH)/get_next_line.c\
		$(READPATH)/ft_save_map.c\
		$(READPATH)/ft_split_to_int.c\
		$(DRAWPATH)/ft_draw_line.c\
		$(DRAWPATH)/ft_bresenham.c\
		$(UTILPATH)/ft_debug.c\
		$(UTILPATH)/ft_clear_memory.c\
		$(UTILPATH)/ft_vector.c\
		$(HOOKPATH)/ft_hook.c\
		$(MATRIXPATH)/ft_apply_matrix.c\
		$(MATRIXPATH)/ft_draw_matrix.c\
		$(MATRIXPATH)/ft_hook_matrix.c\
		$(MATRIXPATH)/ft_matrix.c\
		$(MATRIXPATH)/ft_matrix_init.c\
		$(MATRIXPATH)/ft_transform.c\


OBJ = $(SRC:.c=.o)

NAME = fdf

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@make -C $(MINILIBX)
	@$(CC) $(HEADER) $(LIB) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

clean : 
	@make -C $(LIBFT) clean
	@make -C $(MINILIBX) clean
	rm -rf $(OBJ)

fclean : clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
