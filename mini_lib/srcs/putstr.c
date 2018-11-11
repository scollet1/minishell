#include "../incl/mini_lib.h"

void	putendl_fd(const char *s, int fd)
{
	if (!s)
		return ;
	putstr_fd(s, fd);
	write(fd, "\n", 1);
}

void	putendl(const char *s)
{
	if (!s)
		return ;
	putendl_fd(s, 1);
}

void	putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, mini_strlen(s));
}

void	putstr(const char *s)
{
	if (!s)
		return ;
	putstr_fd(s, 1);
}
