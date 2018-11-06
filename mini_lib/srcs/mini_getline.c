/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:01:26 by scollet           #+#    #+#             */
/*   Updated: 2017/04/21 11:56:37 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/mini_lib.h"

char		*learn_to_read(const short fd, char **block, ssize_t *s)
{
	char	*hold;
	char	tmp[BUFF_SIZE + 1];

	/*
	** read from file descriptor into our temporary buffer. We update
	** the pointer of ret from the getline() function with the amount
	** of bytes read. Bytes read below zero indicates a system error.
	*/
	if ((*s = read(fd, tmp, BUFF_SIZE)) < 0)
		return (NULL);
	tmp[*s] = '\0';
	/*
	** hold the pointer to our file descriptor's buffer
	*/
	hold = block[fd];
	/*
	** join our current buffer with the new bytes read
	*/
	block[fd] = strjoin(hold, tmp);
	/*
	** we don't need hold anymore so we clear its memory. tmp also
	** exists on the stack so we don't have to worry about freeing it
	*/
	mini_memdel((void**)&hold);
	return (block[fd]);
}

/*
** on success mini_getline() will return one of two values:
**	(1)	indicates that there are still bytes to be read
**	(0)	indicates that all bytes have been read
**	(-1)	indicates that there was an error and the Samurai should feel bad
*/
ssize_t		mini_getline(const short fd, char **line)
{
	ssize_t		ret;
	char		*str;
	static char	*block[MAX_FD];

	/*
	** if we receive invalid options, leave. file descriptors below 0 indicate
	** errors and the line passed in must exist on the stack
	*/
	if (!line || fd < 0)
		return (-1);
	/*
	** if a buffer does not exist at our given file descriptor we will create a
	** new empty string
	*/
	if (!block[fd])
		block[fd] = strnew(0);
	ret = 1;
	/*
	** while there is information to be read
	*/
	while (ret > 0)
	{
		/*
		** read bytes of length BUFF_SIZE into our buffer
		*/
		if ((block[fd] = learn_to_read(fd, block, &ret)) && ret < 0)
			return (-1);
		/*
		** search for the newline in our fd buffer
		** TODO : save the string length of the buffer in a variable
		** so we don't have to keep reevaluating how long the buffer
		** actually is
		*/
		if ((str = mini_memchr(block[fd], '\n', mini_strlen(block[fd]))))
		{
			/*
			** "chop" the pointer to the newline with a null delimiter
			*/
			*str = '\0';
			/*
			** duplicate the entire string up to the newline
			*/
			*line = mini_strdup(block[fd]);
			/*
			** move the pointer to directly after the newline character
			** and continue normally
			*/
			mini_memmove(block[fd], str + 1, mini_strlen(str + 1) + 1);
			return (1);
		}
	}
	/*
	** a mini cleanup operation to check any uncleared buffers from the last read
	** string up until the end of the buffer
	*/
	if ((*block[fd]) && (*line = mini_strdup(block[fd])))
		if ((str = mini_memchr(block[fd], '\0', mini_strlen(block[fd]) + 1)) &&
			(mini_memmove(block[fd], str + 1, mini_strlen(str + 1) + 1)))
			return (1);
	return (0);
}
