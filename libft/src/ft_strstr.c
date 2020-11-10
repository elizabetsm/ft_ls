/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:33:32 by cwing             #+#    #+#             */
/*   Updated: 2020/05/07 20:43:18 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	const char	*ret;
	const char	*temp;

	if (!*needle)
		return ((char *)haystack);
	temp = needle;
	while (*haystack)
	{
		ret = haystack;
		while ((*haystack == *needle) && *needle)
		{
			++haystack;
			++needle;
		}
		if (!*needle)
			return ((char *)ret);
		needle = temp;
		haystack = ret + 1;
	}
	return (NULL);
}
