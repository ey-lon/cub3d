#----------------------------------------------
#COLORS

NOCOL = \e[0m
GREEN = \e[1;92m
RED = \e[1;31m
YELL = \e[0;33m
CYAN = \e[1;36m
TCOL = $(CYAN)
RMD = $(GREEN)successfully $(RED)removed$(NOCOL)
CMP = $(GREEN)successfully compiled$(NOCOL)

#----------------------------------------------

CC = cc

RM = rm -rf

NAME = cub3D

CC_FLAGS = -no-pie -Wall -Werror -Wextra -g

MLX_FLAGS = -lm -lX11 -lXext

#----------------------------------------------
#PATHS

SRC_P = src/
MLX_P = minilibx-linux/
LFT_P = libft/

#----------------------------------------------
#FILES

LIBFT = libft.a

MLX = libmlx.a

SRC = main.c \
	get_fd.c \
	get_info.c \
	get_textures.c \
	get_images_paths.c \
	get_images_xpm.c \
	get_colors.c \
	get_map.c \
	check_map.c \
	free_stuff_1.c

#----------------------------------------------
#PREFIXES

SRC := $(addprefix $(SRC_P),$(SRC))
MLX := $(addprefix $(MLX_P),$(MLX))
LIBFT := $(addprefix $(LFT_P),$(LIBFT))

#----------------------------------------------
#OBJECTS

OBJ = $(SRC:.c=.o)
%.o : %.c
	$(CC) -c $< $(LIBFT) $(MLX) $(MLX_FLAGS) -o $@

#----------------------------------------------
#RULES

all: $(NAME)

$(NAME): libcomp $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

libcomp:
	make -C $(LFT_P)

libft_clean:
	make clean -C $(LFT_P)

libft_fclean:
	make fclean -C $(LFT_P)

clean: libft_clean
	$(RM) $(OBJ)

fclean: libft_clean clean
	$(RM) $(NAME)

re: fclean all

bonus:

.PHONY: $(NAME) all re clean fclean bonus

.SILENT: