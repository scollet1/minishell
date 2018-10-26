/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:22:00 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 17:16:17 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/mini_lib.h"

char	*mini_cat(int done, ...)
{
	va_list *ap;
	char 	*ret;
	char 	*str;

	if (!(ret = (char*)memalloc((sizeof(char) * 1))))
		return (NULL);
	va_start(ap, NULL);
	while (!done)
	{
		str = va_arg(ap, char*);
		ret = mini_strcat(ret, str);
		done--;
	}
	va_end(ap);
	return (ret);
}

char	*mini_strcat(char *s1, const char *s2)
{
	mini_strcpy(&s1[mini_strlen(s1)], s2);
	return (s1);
}