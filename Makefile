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

NAME = cub3d

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
	map_check.c \
	mat_fd.c

#----------------------------------------------
#PREFIXES

SRC := $(addprefix $(SRC_P),$(SRC))
MLX := $(addprefix $(MLX_P),$(MLX))
LIBFT := $(addprefix $(LFT_P),$(LIBFT))

#----------------------------------------------
#OBJECTS

OBJ = $(SRC:.c=.o)

#----------------------------------------------
#RULES

all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

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