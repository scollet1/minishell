/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:15:56 by scollet           #+#    #+#             */
/*   Updated: 2017/03/07 20:27:26 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/mini_lib.h"

char	*strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!(s))
		return (0);
	if (!(sub = (char*)memalloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = 0;
	return (sub);
}
