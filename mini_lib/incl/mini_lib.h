#ifndef MINI_LIB_H
# define MINI_LIB_H

# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef ERR_SYS
# define

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
void				mini_bzero(void *s, size_t n);

/*
** Numbers
*/
int					atoi(const char *str);

/*
** Stack
*/
void				dump_stack(t_list *list, void (*func)(void*));
int					push(t_list **list, void *data, size_t size);

/*
** Strings
*/
char				*mini_cat(int done, ...);
char				*mini_strcat(char *s1, const char *s2);
ssize_t				mini_getline(const short fd, char **line);
unsigned int		count_words(const char *s, char c);


char				*itoa(int n);
char				*itoa_base(int n, int base);
void				lstadd(t_list **alst, t_list *new);
void				lstdel(t_list **alst, void (*del)(void*, size_t));
void				lstdelone(t_list **alst, void (*del)(void*, size_t));
void				lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*lstnew(void const *content, size_t content_size);
void				*memalloc(size_t size);
void				*memccpy(void *dst, const void *src, int c, size_t n);
void				*mini_memchr(const void *s, int c, size_t n);
int					mini_memcmp(const void *s1, const void *s2, size_t n);
void				*mini_memcpy(void *dst, const void *src, size_t n);
void				mini_memdel(void **ap);
void				*mini_memmove(void *dst, const void *src, size_t len);
void				*mini_memset(void *str, int c, size_t n);
void				mini_putchar(char c);
void				putchar_fd(char c, int fd);
void				putendl(const char *s);
void				putendl_fd(const char *s, int fd);
void				putnbr(int n);
void				putnbr_fd(int n, int fd);
void				putstr(const char *s);
void				putstr_fd(const char *s, int fd);
char				*strchr(const char *s, int c);
void				strclr(char *s);
int					strcmp(const char *s1, const char *s2);
char				*mini_strcpy(char *dst, const char *src);
void				strdel(char **as);
char				*mini_strdup(const char *s1);
int					strequ(const char *s1, const char *s2);
void				striter(char *s, void (*f)(char *));
void				striteri(char *s, void (*f)(unsigned int, char *));
char				*strjoin(const char *s1, const char *s2);
size_t				strlcat(char *dst, const char *src, size_t size);
size_t				mini_strlen(const char *s);
char				*strmap(const char *s, char (*f)(char));
char				*strmapi(const char *s, char(*f)(unsigned int, char));
char				*mini_strncat(char *s1, const char *s2, size_t n);
int					strncmp(const char *s1, const char *s2, size_t n);
char				*mini_strncpy(char *dst, const char *src, size_t len);
int					strnequ(const char *s1, const char *s2, size_t n);
char				*strnew(size_t size);
char				*strnstr(const char *big, const char
		*little, size_t len);
char				*strrchr(const char *s, int c);
char				**strsplit(const char *s, char c);
char				*strstr(const char *big, const char *little);
char				*strsub(const char *s, unsigned int start, size_t len);
char				*strtrim(const char *s);
int					tolower(int c);
int					toupper(int c);

#endif
