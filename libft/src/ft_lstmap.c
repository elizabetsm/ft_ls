/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:22:59 by cwing             #+#    #+#             */
/*   Updated: 2020/05/07 20:38:01 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*null;
	t_list	**fin;
	t_list	**new;

	null = NULL;
	new = &null;
	fin = new;
	while (lst != NULL)
	{
		*new = f(lst);
		new = &(*new)->next;
		lst = lst->next;
	}
	return (*fin);
}
