NAME = fractol
SRCS = fract-ol.c commands.c fracts.c utils.c
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
	@echo "Complied chief"
	$(COMPILER) $(OBJS) $(LIBFTDIR) -I includes/LIBFT $(MLXFLAGS) -o $(NAME) $(MINILIBX) -L/usr/X11R6/lib -lX11 -lXext -lm

$(LIBFTDIR): 
	$(MAKE) -C includes/LIBFT

$(MINILIBX): $(MINILIBX_DIR)
	$(MAKE) -C $(MINILIBX_DIR)

$(MINILIBX_DIR):
	wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz -O minilibx
	tar -xzvf minilibx
	rm minilibx

%.o: %.c $(HEADER)
	$(COMPILER) -I includes/LIBFT -c $< -o $@

clean:
	@echo "Deleted chief"
	$(RM) $(OBJS)
	$(MAKE) -C includes/LIBFT clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	@echo "Deleted Everything chief"
	$(RM) $(NAME)
	$(MAKE) -C includes/LIBFT fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
.SILENT: