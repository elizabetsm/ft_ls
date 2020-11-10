/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:57:33 by cwing             #+#    #+#             */
/*   Updated: 2020/05/14 15:50:39 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	const unsigned char		*temp_src;
	unsigned char			*temp_dest;
	size_t					iter;

	temp_src = src;
	temp_dest = dest;
	iter = 0;
	if (size == 0 || dest == src)
		return ((void*)(dest));
	while (iter < size)
	{
		temp_dest[iter] = temp_src[iter];
		iter++;
	}
	return ((void*)temp_dest);
}
