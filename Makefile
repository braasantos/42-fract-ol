NAME = fractol
SRCS = fract-ol.c
HEADER = fractol.h
LIBFTDIR = includes/LIBFT/libft.a
MINILIBX = minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = minilibx-linux/
MLXFLAGS = -lX11 -lXext
CC = cc
CFLAGS = -Wall -Werror -Wextra
COMPILER = $(CC) $(CFLAGS)
RM = rm -f
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR) $(MINILIBX_DIR) $(MINILIBX)
	@echo "Created objs"
	$(COMPILER) $(OBJS) $(LIBFTDIR) -I includes/LIBFT $(MLXFLAGS) -o $(NAME) $(MINILIBX) -L/usr/X11R6/lib -lX11 -lXext -lm

$(LIBFTDIR): 
	$(MAKE) -C includes/LIBFT

$(MINILIBX): $(MINILIBX_DIR)
	$(MAKE) -C $(MINILIBX_DIR)

$(MINILIBX_DIR):
	wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz -O minilibx
	tar -xzvf minilibx
	rm minilibx

<<<<<<< HEAD
# $(MINILIBX):
# 	wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz -O minilibx
# 	tar -xzvf minilibx
# 	rm minilibx

%.o: %.c
=======
%.o: %.c $(HEADER)
>>>>>>> c3670a7a86721a93e9cae94e8f21c06aaf75a23c
	$(COMPILER) -I includes/LIBFT -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C includes/LIBFT clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	@echo "Deleted objs"
	$(RM) $(NAME)
	$(MAKE) -C includes/LIBFT fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
