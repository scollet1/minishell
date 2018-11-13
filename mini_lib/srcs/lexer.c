#include "../incl/mini_lib.h"

char 	end_tok(char *start, char delim, char **token, size_t len)
{
	char *end;

	if ((end = mini_memchr(start, delim, len)))
	{
		*token = strndup(start, end - start);
		return ('!');
	}
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
//		printf("%c\n", (char)delims->head->data);
		start = mini_memchr(str, (char)delims->head->data, len);
		if (start > str)
		{
			*token = strndup(str, start - str);
			return '?';
		}
		if (start++)
		{
			if (delims->head->next)
			{
				if (mini_memcmp(start, mini_memchr(str, (char)
						delims->head->next->data, len), sizeof(start)) < 0)
					ret = end_tok(start, (char)delims->head->data, token, len);
			}
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
	char ret;
	char *token;

	ret = '\0';
	while (*str)
	{
		if ((ret = tokenize(str, delims, &token)) == '?')
		{
			if (enqueue(tokens, token, sizeof(token)) == FAILURE)
				return (0);
			str += mini_strlen(token);
		}
		else
		{
			if (enqueue(tokens, token, sizeof(token)) == FAILURE)
				return (0);
//			printf("%s\n", (char*)(*tokens)->head->data);
			str += mini_strlen(token) + 2;
		}
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
//		printf("%c\n", (char)delims->head->data);
		args--;
	}
	va_end(ap);
	return (lex_tok(str, tokens, delims));
}