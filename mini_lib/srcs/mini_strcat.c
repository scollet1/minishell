#include "../incl/mini_lib.h"

char	*nullcat(char *str, size_t len)
{
	char	*tmp;
	char 	*ret;
	t_list	*queue;

	while (len > 0)
	{
		if ((tmp = mini_memchr(str, '\0', len)))
		{
			ret = mini_strdup(str);
			str = tmp + 1;
			len -= tmp - ret;
			enqueue(&queue, (void*)&ret, sizeof(ret));
		}
	}
	return (cat_queue(&queue));
}

char	*strjoin(const char *s1, const char *s2)
{
	char	*tmp;

	if (s1 == 0 && s2 == 0)
		return (strnew(0));
	else if (s1 == 0)
		return (mini_strdup(s2));
	else if (s2 == 0)
		return (mini_strdup(s1));
	if (!(tmp = strnew(mini_strlen(s1) + mini_strlen(s2))))
		return (0);
	mini_memmove(tmp, s1, mini_strlen(s1));
	mini_memmove(&tmp[mini_strlen(s1)], s2, mini_strlen(s2));
	return (tmp);
}

size_t	mini_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	char		*d;
	const char	*s;
	size_t		ret;

	d = dst;
	s = src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	ret = d - dst;
	n = size - ret;
	if (n == 0)
		return (ret + mini_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (ret + (s - src));
}

char	*mini_cat(int args, ...)
{
	va_list ap;
	char 	*ret;
	char 	*str;

	if (!(ret = (char*)memalloc((sizeof(char) * 1))))
		return (NULL);
	str = NULL;
	va_start(ap, args);
	while (args > 0)
	{
		str = va_arg(ap, char*);
		ret = strjoin(ret, str);
		args--;
	}
	va_end(ap);
	return (ret);
}

char	*mini_strcat(char *s1, const char *s2)
{
	mini_strcpy(&s1[mini_strlen(s1)], s2);
	return (s1);
}

char *mini_join(char **strs, const char *delim)
{
	char	*str;

	if (!strs || !*strs)
		return (NULL);
	str = strndup(*strs, mini_strlen(*strs));
	while (*(++strs))
	{
		if (delim)
			str = mini_strncat(str, delim, mini_strlen(str));
		str = mini_strncat(str, *strs, mini_strlen(str));
	}
	return (str);
}