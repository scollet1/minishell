NAME = mini_lib.a

CC = gcc

OBJ = obj/*.o

CCFLAGS = -I.incl -Wall -Wextra -Werror -c -g

RM = -rm -fr

ARCHIVE = ar rc

INDEX = ranlib

HEADER = incl/mini_lib.h

FILES = mini_stack.c putstr.c node.c list.c mini_strlen.c           \
        mini_memcpy.c mini_getline.c strnew.c mini_memmove.c        \
        mini_strcat.c mini_strcpy.c mini_memdel.c mini_memchr.c     \
        mini_strcmp.c strsplit.c strsub.c memalloc.c mini_memset.c  \
        mini_bzero.c mini_atoi.c strings.c mini_queue.c tree.c      \
        lexer.c mini_memcmp.c node.c mini_strncat.c


SRC_DIR = srcs

SRC = $(addprefix $(SRC_DIR)/, $(FILES))

$(NAME):
		$(shell mkdir obj)
		$(CC) $(CCFLAGS) $(SRC)
		mv *.o obj
		$(ARCHIVE) $(NAME) $(OBJ)
		$(INDEX) $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)
