NAME = fractol
SRCS = fract-ol.c
HEADER = fractol.h
LIBFTDIR = includes/LIBFT/libft.a
#MINILIBX = minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = minilibx-linux/
MLXFLAGS = -lX11 -lXext
CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3                                                   
COMPILER = $(CC) $(CFLAGS)
RM = rm -f
OBJS = $(SRCS:.c=.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFTDIR) $(HEADER) $(MINILIBX_DIR) $(MINILIBX)
	@echo "Created objs"
	$(COMPILER) $(OBJS) $(LIBFTDIR) -I includes/LIBFT $(MLXFLAGS) -o $(NAME) $(MINILIBX)

$(LIBFTDIR):
	$(MAKE) -C includes/LIBFT

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(MINILIBX_DIR):
	wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz -O minilibx
	tar -xzvf minilibx
	rm minilibx

$(MINILIBX):
	wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz -O minilibx
	tar -xzvf minilibx
	rm minilibx

%.o: %.c
	$(COMPILER) -I includes/LIBFT -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C includes/LIBFT clean

fclean: clean
	@echo "Deleted objs"
	$(RM) $(NAME)
	$(MAKE) -C includes/LIBFT fclean

re: fclean all

.PHONY: all clean fclean re bonus