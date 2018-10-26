
NAME = minishell

CC = gcc

SRC_DIR = src

CFLAGS  = -Wall -Werror -Wextra -fsanitize=address

INCL = -I incl

LIBHERMES = ./mini_lib/

SRC_DIR = srcs
SRC_FILES = mini_main.c mini_error.c

PARSE_DIR = src/parsing
PARSE_FILES = h_custom_payload.c h_files.c h_performace_opts.c h_portlists.c
PARSE_FILES += h_host_discovery.c h_scan.c h_timeouts.c h_worker.c
PARSE_FILES += h_output_ops.c parse_file.c
PARSE_FILES += parse_ip.c parse_ports.c parse_time.c parser.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC += $(addprefix $(PARSE_DIR)/, $(PARSE_FILES))

RM = rm -fr

$(NAME):
		$(MAKE) -C $(LIBHERMES) re
		$(CC) $(CFLAGS) $(INCL) $(SRC) $(LIBHERMES)/libhermes.a -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)