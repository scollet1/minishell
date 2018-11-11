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
	char	tmp[BUFF_SIZE + 1];
	char	*hold;

	if ((*s = read(fd, tmp, BUFF_SIZE)) < 0)
		return (NULL);
	tmp[*s] = '\0';
	hold = block[fd];
	block[fd] = strjoin(hold, tmp);
	mini_memdel((void**)&hold);
	return (block[fd]);
}

ssize_t		mini_getline(const short fd, char **line)
{
	ssize_t		ret;
	char		*str;
	static char *block[MAX_FD];

	if (!line || fd < 0)
		return (-1);
	if (!block[fd])
		block[fd] = strnew(0);
	ret = 1;
	while (ret > 0)
	{
		if ((block[fd] = learn_to_read(fd, block, &ret)) && ret < 0)
			return (-1);
		if ((str = mini_memchr(block[fd], '\n', mini_strlen(block[fd]))))
		{
			*str = '\0';
			*line = mini_strdup(block[fd]);
			mini_memmove(block[fd], str + 1, mini_strlen(str + 1) + 1);
			return (1);
		}
	}
	if ((*block[fd]) && (*line = mini_strdup(block[fd])))
		if ((str = mini_memchr(block[fd], '\0', mini_strlen(block[fd]) + 1)) &&
			(mini_memmove(block[fd], str + 1, mini_strlen(str + 1) + 1)))
			return (1);
	return (0);
}

#ifdef TEST_GETLINE
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2) {
		fd = mini_atoi(av[1]);
		mini_getline(fd, &line);
		printf("%s\n", line);
	} else {
		printf("not enough arguments\n");
	}
	return (0);
}
#endif