/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 23:45:11 by cwing             #+#    #+#             */
/*   Updated: 2020/05/07 20:38:32 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memccpy(void *dest, const void *src, int ch,
										size_t size)
{
	const unsigned char		*temp_src;
	unsigned char			*temp_dest;
	unsigned char			sh;
	size_t					iter;

	iter = 0;
	temp_src = src;
	temp_dest = dest;
	sh = (unsigned char)ch;
	if ((int)size == 0)
		return (NULL);
	while (iter < size)
	{
		temp_dest[iter] = temp_src[iter];
		if (temp_src[iter] == sh)
			return ((void*)(dest + iter + 1));
		iter++;
	}
	return (NULL);
}
