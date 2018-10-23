NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

.PHONY: clean fclean all re 

SRC_DIR = src

SRC_FILES = main.c reading_inform.c memdelalloc/initialization.c\
		errors/errors.c memdelalloc/purification.c processing/vertex_proc.c\
        errors/errors1.c processing/eage_proc.c check_information.c\
        possible_ways.c depth_first_search.c vertex_sort.c\
        processing/procants.c processing/procways.c searchft.c\
        additional_func.c additional_func1.c errors/errors2.c

SRC_OBJ = $(addprefix $(SRC_DIR)/, $(SRC_FILES:.c=.o))

LIB_DIR = lib

LIB_FILES = mylib/mylib.a mylib/libft/libft.a

LFILES = $(addprefix $(LIB_DIR)/, $(LIB_FILES))

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C lib/mylib
	$(CC) $(CFLAGS) $(SRC_OBJ) $(LFILES) -o $(NAME)

clean:
	rm -f $(SRC_OBJ)
	rm -f *~
	make clean -C lib/mylib

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/mylib

re: fclean all