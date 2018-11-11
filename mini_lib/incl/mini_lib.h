#ifndef MINI_LIB_H
# define MINI_LIB_H

# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# if __STDC_VERSION__ < 199901L
	# if __GNUC__ >= 2
		# define __func__ __FUNCTION__
	# else
		# define __func__ "<unknown>"
	# endif
# endif

/*
** FATAL ERRORS
*/

# ifndef FATAL_ERR
	# define FATAL_ERR "FATAL ERROR"
# endif

# ifndef ERR_SYSTEM
	# define ERR_SYSTEM -1
# endif

# ifndef ERR_PROCESS
	# define ERR_PROCESS -2
# endif

/*
** NON-FATAL ERRORS
*/

# ifndef NON_FATAL_ERR
	# define NON_FATAL_ERR "NON-FATAL ERROR"
# endif

# ifndef ERR_UNKOWN
	# define ERR_UNKOWN 1
# endif

# ifndef ERR_INVALID
	# define ERR_INVALID 2
# endif

# ifndef ERR_EXIT
	# define ERR_EXIT 3
# endif

/*
**
*/

# ifndef WHICH
	# define WHICH(var) (#var)
# endif

# ifndef SUCCESS
	# define SUCCESS 0
# endif

# ifndef FAILURE
	# define FAILURE -1
# endif

# ifndef BUFF_SIZE
	# define BUFF_SIZE 42
# endif

# ifndef MAX_FD
	# define MAX_FD 0xFFFF
# endif

/*
** a node in our doubly linked
** list with a void pointer
** to any data type, described
** by size
*/
typedef struct		s_node
{
	size_t			size;
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*
** a linked list of length with
** pointers to head and tail
** offering O(1) access with
** appending or popping
** from either side of the
** list, as well as a
** convenient exit condition
** during list traversal
*/
typedef struct		s_list
{
	size_t 			len;
	t_node			*head;
	t_node			*tail;
}					t_list;

/*
** Helpers
*/
int					isalnum(int c);
int					isalpha(int c);
int					isascii(int c);
int					isdigit(int c);
int					isprint(int c);

/*
** Lists
*/
t_list				*new_list(void);
t_node				*new_node(void *data, size_t size);

/*
** Memory
*/
void				mini_memdel(void **ap);
void				*memalloc(size_t size);
void				mini_bzero(void *s, size_t n);
void				*mini_memset(void *str, int c, size_t n);
void				*mini_memchr(const void *s, int c, size_t n);
void				*mini_memcpy(void *dst, const void *src, size_t n);
void				*mini_memccpy(void *dst, const void *src, int c, size_t n);
int					mini_memcmp(const void *s1, const void *s2, size_t n);
void				*mini_memmove(void *dst, const void *src, size_t len);

/*
** Numbers
*/
char				*itoa(int n);
char				*itoa_base(int n, int base);
int					mini_atoi(const char *str);
void				putnbr(int n);
void				putnbr_fd(int n, int fd);

/*
** Stack
*/
void				dump_stack(t_list *list, void (*func)(void*));
int					push(t_list **list, void *data, size_t size);

/*
** Queue
*/
void				dump_queue(t_list **queue, void (*func)(void*));
int					enqueue(t_list **list, void *data, size_t size);

/*
** Strings
*/
void				strclr(char *s);
void				strdel(char **as);
void				mini_putchar(char c);
char				*strnew(size_t size);
char				*mini_cat(int done, ...);
void				putstr(const char *s);
void				putendl(const char *s);
size_t				mini_strlen(const char *s);
void				putchar_fd(char c, int fd);
char				*mini_strdup(const char *s1);
char				*strchr(const char *s, int c);
void				putstr_fd(const char *s, int fd);
void				putendl_fd(const char *s, int fd);
unsigned int		count_words(const char *s, char c);
void				striter(char *s, void (*f)(char *));
char				*mini_strcat(char *s1, const char *s2);
int					strcmp(const char *s1, const char *s2);
ssize_t				mini_getline(const short fd, char **line);
char				*mini_strcpy(char *dst, const char *src);
int					strequ(const char *s1, const char *s2);
void				striteri(char *s, void (*f)(unsigned int, char *));
char				*strjoin(const char *s1, const char *s2);
size_t				mini_strlcat(char *dst, const char *src, size_t size);
char				*strmap(const char *s, char (*f)(char));
char				*strmapi(const char *s, char(*f)(unsigned int, char));
char				*mini_strncat(char *s1, const char *s2, size_t n);
int					mini_strncmp(const char *s1, const char *s2, size_t n);
char				*mini_strncpy(char *dst, const char *src, size_t len);
int					strnequ(const char *s1, const char *s2, size_t n);
char				*strnstr(const char *big, const char
*little, size_t len);
char				*strrchr(const char *s, int c);
char				**strsplit(const char *s, char c);
char				*strstr(const char *big, const char *little);
char				*strsub(const char *s, unsigned int start, size_t len);
char				*strtrim(const char *s);
int					tolower(int c);
int					toupper(int c);



void				lstadd(t_list **alst, t_list *new);
void				lstdel(t_list **alst, void (*del)(void*, size_t));
void				lstdelone(t_list **alst, void (*del)(void*, size_t));
void				lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*lstnew(void const *content, size_t content_size);

#endif
