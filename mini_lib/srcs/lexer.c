#include "../incl/mini_lib.h"

char	tokenize(char *str, t_list *delims, char **token)
{
	size_t	len;
	t_node	*head;

	char 	ret;
	char	*tmp;
	char	*end;
	char	*start;

	if (!*str || !delims)
		return (0);
	ret = 0;
	end = NULL;
	len = mini_strlen(str);
	head = delims->head;
	while (delims->head != delims->tail)
	{
		if (!(tmp = mini_memchr(
				str,
				(char)delims->head->data,
				len
		)))
		{
			*token = strndup(str, len);
			return ('.');
		}
		if (mini_memcmp(tmp,
						mini_memchr(str,
									(char)delims->head->next->data,
									len),
						sizeof(tmp)) < 0)
		{
			start = tmp;
			if (!(end = mini_memchr(str, (char)delims->head->data, len)))
			{
				*token = strndup(start, len);
				return ((char)delims->head->data);
			}
		}
		delims->head = delims->head->next;
	}
	delims->head = head;
	*token = strndup(start, end - start);
	return ('!');
}

char	lex_tok(char *str, t_list **tokens, t_list **delims)
{
	char	ret;
	char	*token;

	ret = '!';
	while (ret != '.')
	{
		ret = tokenize(str, *delims, &token);
//		if (!mini_strncmp(token, ret, 1))
//			return ('!');
		if (enqueue(tokens, token, sizeof(token)) == FAILURE)
			return (0);
	}
	return (ret);
}

char	lex(t_list **tokens, char *str, int args, ...)
{
	va_list	ap;
	char	arg;
	t_list	*delims;

	va_start(ap, args);
	delims = new_list();
	*tokens = new_list();
	while (args)
	{
		arg = va_arg(ap, int);
		enqueue(&delims, &arg, sizeof(arg));
		args--;
	}
	va_end(ap);
	return (lex_tok(str, tokens, &delims));
}