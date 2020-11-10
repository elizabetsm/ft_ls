/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:01:24 by cwing             #+#    #+#             */
/*   Updated: 2020/05/12 15:30:36 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strcmp(const char *s1, const char *s2)
{
	size_t		iter;

	iter = 0;
	while (s1[iter])
	{
		if (s1[iter] != s2[iter])
			return ((unsigned char)s1[iter] - (unsigned char)s2[iter]);
		else
			iter++;
	}
	return ((unsigned char)s1[iter] - (unsigned char)s2[iter]);
}
