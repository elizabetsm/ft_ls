/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:19:00 by cwing             #+#    #+#             */
/*   Updated: 2020/05/15 15:51:36 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	ptr = NULL;
	if ((ptr = (t_list *)malloc(sizeof(t_list))))
	{
		ptr->content = ft_memalloc(content_size + 1);
		if (ptr->content)
		{
			ft_memcpy(ptr->content, content, content_size);
			ptr->content_size = content_size;
			ptr->next = NULL;
		}
		else
			ft_memdel((void**)&ptr);
	}
	return (ptr);
}
