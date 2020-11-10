/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:46:15 by cwing             #+#    #+#             */
/*   Updated: 2020/05/14 12:40:21 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*temp1;
	unsigned char		*temp2;
	int					iter;

	temp1 = (unsigned char*)s1;
	temp2 = (unsigned char*)s2;
	iter = 0;
	while (iter < (int)n)
	{
		if (temp1[iter] != temp2[iter])
			return (temp1[iter] - temp2[iter]);
		iter++;
	}
	return (0);
}
