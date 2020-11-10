/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:06:46 by cwing             #+#    #+#             */
/*   Updated: 2020/05/07 20:40:59 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strdup(const char *s1)
{
	char	*dst;

	dst = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dst)
	{
		ft_strcpy(dst, s1);
		return (dst);
	}
	else
		return (NULL);
}
