NAME = minishell

CC = gcc

SRC_DIR = src

CFLAGS  = -Wall -Werror -Wextra -fsanitize=address

INCL = -I incl

MINILIB = ./mini_lib/

SRC_DIR = srcs
SRC_FILES = mini_main.c mini_error.c mini_init.c        \
            mini_dispatch.c mini_parser.c mini_exit.c   \
            mini_env.c mini_echo.c mini_print.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

RM = rm -fr

$(NAME):
		$(MAKE) -C $(MINILIB) re
		$(CC) $(CFLAGS) $(INCL) $(SRC) $(MINILIB)/mini_lib.a -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)