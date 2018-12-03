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

	char	*end;
	char    *doubq;
	char	*singq;

	if (!str || !delims)
		return (0);
	len = mini_strlen(str);
    singq = mini_memchr(str, '\'', len);
    doubq = mini_memchr(str, '\"', len);

    char function(char c, char **token, char *str, size_t len) {
        *token = strndup(str, len);
        printf("token %s returning %c\n", *token, c);
        return (c);
    }
	printf("sing %s doub %s str %s\n", singq, doubq, str);
    if (singq) {
        if (doubq) {
            if (singq < doubq) {
                printf("sinq %s doub %s\n", singq, doubq);
                if (singq > str) {
                    printf("sing > str\n");
                    return function('!', token, str, singq - str);
                }
                else if (!(end = mini_memchr(++singq, '\'', len)))
                    return function('\'', token, ++str, len);
                else {
                    printf("%s %s\n", end, singq);
                    return function('!', token, str, ++end - singq);
                }
            }
            else if (doubq > str) {
                return function('!', token, str, doubq - str);
            }
            else if (!(end = mini_memchr(++doubq, '\"', len)))
                return function('\"', token, ++str, len);
            else
                return function('!', token, str, end - doubq);
        }
        else if (!(end = mini_memchr(singq, '\'', len)))
            return function('\'', token, ++str, len);
        else {
            printf("%s %s\n", end, singq);
            return function('!', token, str, ++end - singq);
        }
    }
	else if (doubq)
	{
        printf("doub %s\n", doubq);
        if (doubq > str) {
            *token = strndup(str, doubq - str);
            printf("%s\n", *token);
        }
	    else if (!(end = mini_memchr(++doubq, '\"', len)))
	        return function('\"', token, ++str, len);
	    else
	        *token = strndup(str, end - doubq);
	    printf("end %s\n", end);
    }
	else
        *token = strndup(str, len);
 	return ('!');
	/*
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
	 */
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
			printf("return tok %s\n", token);
			str += ret == '!' ? len:len + 2;
			printf("str %s\n", str);
		}
	}
//	printf("%c\n", ret);
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