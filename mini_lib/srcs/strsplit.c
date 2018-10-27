#include "../incl/mini_lib.h"

unsigned int	count_words(const char *s, char c)
{
	unsigned int split;
	unsigned int split_t;

	split_t = 0;
	split = 0;
	while (*s)
	{
		if (split_t == 1 && *s == c)
			split_t = 0;
		if (split_t == 0 && *s != c)
		{
			split_t = 1;
			split++;
		}
		s++;
	}
	return (split);
}


char		**strsplit(char const *s, char c)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		split;
	unsigned int		start;
	char				**ret;

	if (s == 0 || c == 0)
		return (0);
	split = count_words(s, c);
	if (!(ret = (char**)malloc((sizeof(char*) * (split + 1)))))
		return (0);
	i = 0;
	j = 0;
	while (j < split)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		ret[j] = strsub(s, start, i - start);
		i++;
		j++;
	}
	ret[j] = 0;
	return (ret);
}