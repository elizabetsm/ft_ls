/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 01:53:27 by cwing             #+#    #+#             */
/*   Updated: 2020/04/27 19:09:04 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lst_push_back(t_list **alst,
		void const *content, size_t content_size)
{
	t_list			*temp;
	t_list			*find;

	find = *alst;
	temp = NULL;
	if (alst && (temp = ft_lstnew(content, content_size)))
	{
		while (find->next)
			find = find->next;
		find = temp;
	}
	else
		*alst = temp;
}
