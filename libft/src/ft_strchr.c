/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:52:56 by cwing             #+#    #+#             */
/*   Updated: 2020/05/07 20:40:27 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char		*ft_strchr(const char *s, int c)
{
	char	*s1;

	s1 = (char*)s;
	if (c == '\0' && ft_strlen(s1) == 2)
		return ((char *)s);
	while (s1)
	{
		if (((char *)s1)[0] == (char)c)
		{
			break ;
		}
		if (s1[0] == '\0')
			return (NULL);
		++s1;
	}
	return (s1);
}
