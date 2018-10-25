NAME = libhermes.a

CC = gcc

OBJ = obj/*.o

CCFLAGS = -I.incl -Wall -Wextra -c

RM = -rm -fr

ARCHIVE = ar rc

INDEX = ranlib

HEADDR = incl/libhermes.h

FILES = memory.c

SRC_DIR = src

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