NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -O2

MLX_DIR     = ./minilibx/minilibx-linux
LIB_DIR     = ./Libft
GNL_DIR     = ./get_next_line

INCLUDES    = -I ./includes -I $(MLX_DIR) -I $(LIB_DIR) -I $(GNL_DIR)
CFLAGS      += $(INCLUDES)

LIB_NAME    = $(LIB_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

LDFLAGS     = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

GNL_SRC     = $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_util.c

SRC         = ./srcs/main.c \
              ./srcs/global.c \
              ./srcs/init.c \
              ./srcs/free.c \
              ./srcs/event.c \
              ./srcs/utils.c \
              ./srcs/vector.c \
              ./srcs/readfile.c \
              ./srcs/render/draw.c \
              ./srcs/render/raycasting.c \
              ./srcs/render/render.c \
              ./srcs/render/texture.c \
              ./srcs/parser.c \
              ./srcs/parser_util.c \
              ./srcs/parser_path.c \
              ./srcs/parser_color.c \
              ./srcs/line_util.c \
              ./srcs/error.c \
              ./srcs/map.c \
              ./srcs/map_util.c \
              ./srcs/map_surround.c \
              $(GNL_SRC)

OBJS        = $(SRC:%.c=%.o)

all: $(MLX) $(LIB_NAME) $(NAME)

$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $^ $(LIB_NAME) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
