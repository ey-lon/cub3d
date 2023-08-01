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

SRC_F = src/
MLX_F = minilibx-linux/
LFT_F = libft/
OBJ_F = obj/

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
	init_pos.c \
	print_map.c \
	utils.c \
	free_stuff_1.c

#----------------------------------------------
#PREFIXES

MLX := $(addprefix $(MLX_F),$(MLX))
LIBFT := $(addprefix $(LFT_F),$(LIBFT))

#----------------------------------------------
#OBJECTS

OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJ_F),$(OBJ))

$(OBJ_F)%.o : $(SRC_F)%.c
	mkdir -p $(OBJ_F)
	$(CC) -c $< -o $@

#----------------------------------------------
#RULES

all: $(NAME)

$(NAME): libcomp $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	echo "$(CYAN)[make - $(NAME)]$(NOCOL)"

libcomp:
	make -C $(LFT_F)

libft_clean:
	make clean -C $(LFT_F)

libft_fclean:
	make fclean -C $(LFT_F)

clean: libft_clean
	$(RM) $(OBJ)
	$(RM) $(OBJ_F)
	echo "$(CYAN)[make clean - $(NAME)]$(NOCOL)"

fclean: libft_fclean clean
	$(RM) $(NAME)
	echo "$(CYAN)[make fclean - $(NAME)]$(NOCOL)"

re: fclean all

bonus: all

.PHONY: $(NAME) all re clean fclean bonus libcomp libft_clean libft_fclean

.SILENT: