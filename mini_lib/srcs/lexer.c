#include "../incl/mini_lib.h"

char 	end_tok(char *start, char delim, char **token, size_t len)
{
	char *end;

	if ((end = mini_memchr(start, delim, len)))
	{
		*token = strndup(start, end - start);
		return ('!');
	}
	*token = strndup(start, len);
	return (delim);
}

char	tokenize(char *str, t_list *delims, char **token)
{
	size_t	len;
	t_node	*head;

	char 	ret;
	char	*start;

	if (!str || !delims)
		return (0);
	len = mini_strlen(str);
	head = delims->head;
	while (delims->head)
	{
		start = mini_memchr(str, (char)delims->head->data, len);
		if (start > str)
		{
			*token = strndup(str, start - str);
		}
		if (start)
		{
			if (delims->head->next)
			{
				if (mini_memcmp(start, mini_memchr(str, (char)
						delims->head->next->data, len), sizeof(start)) > 0)
				{
					ret = end_tok(start, (char) delims->head->data, token,
									   len);
				}
				else
					ret = end_tok(start, (char) delims->head->next->data, token,
								   len);
			}
//			else if (start > str)
//				*token = strndup(str, start - str);
			else
				ret = end_tok(start, (char)delims->head->data, token, len);
		}
		delims->head = delims->head->next;
	}
	delims->head = head;
	return (ret);
}

char	lex_tok(char *str, t_list **tokens, t_list *delims)
{
	char 	c;
	char	ret;
	size_t	len;
	char	*token;

	c = ' ';
	ret = '\0';
	while (*str)
	{
		ret = tokenize(str, delims, &token);
		if (*token)
		{
			len = mini_strlen(token);
			if (is_allchar(token, c, len) > 0)
			{
				if (enqueue(tokens, &" ", len) == FAILURE)
					return (0);
			}
			else if (enqueue(tokens, &token, len) == FAILURE)
				return (0);
			str += (ret == '?') ? len : len + 2;
		}
		else
			*str = 0;
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
		arg = (char)va_arg(ap, int);
		enqueue(&delims, &arg, sizeof(arg));
		args--;
	}
	va_end(ap);
	return (lex_tok(str, tokens, delims));
}