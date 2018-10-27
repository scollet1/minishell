/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:48:24 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 18:13:07 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
