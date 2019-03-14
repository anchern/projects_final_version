NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

.PHONY: clean fclean all re 

SRC_DIR = src

SRC_FILES = main.c get_inform.c initialisation.c\
			wu_alg.c rotation.c key_hook.c print_map.c\
			move.c zoom.c row_proc.c dy_proc.c dx_proc.c

SRC_OBJ = $(addprefix $(SRC_DIR)/, $(SRC_FILES:.c=.o))

LIB_DIR = lib

LIB_FILES = mylib/mylib.a mylib/libft/libft.a minilibx_macos/libmlx.a

LFILES = $(addprefix $(LIB_DIR)/, $(LIB_FILES))

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C lib/mylib
	make -C lib/minilibx_macos
	$(CC) $(CFLAGS) $(SRC_OBJ) $(LFILES) -o $(NAME)  -framework OpenGL -framework AppKit

clean:
	rm -f $(SRC_OBJ)
	rm -f *~
	make clean -C lib/mylib
	make clean -C lib/minilibx_macos

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/mylib
	make clean -C lib/minilibx_macos


re: fclean all