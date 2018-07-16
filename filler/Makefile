NAME = achernys.filler

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

.PHONY: clean fclean all re 

SRC_DIR = src

SRC_FILES = main.c initialization.c\
        parseinformation.c procvalue.c additional_func.c\
        substitute_figure01.c substitute_figure02.c\
        additional_func02.c dataprocessing.c

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