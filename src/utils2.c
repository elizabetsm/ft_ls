/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:25:31 by cwing             #+#    #+#             */
/*   Updated: 2020/05/18 16:53:29 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				*get_full_name(char *path_name, char *name)
{
	char			*full_name;

	full_name = ft_strnew(PATH_MAX + NAME_MAX);
	if (full_name)
	{
		ft_strncpy(full_name, path_name, PATH_MAX + NAME_MAX);
		ft_strncat(full_name, "/", PATH_MAX + NAME_MAX);
		ft_strncat(full_name, name, PATH_MAX + NAME_MAX);
	}
	return (full_name);
}

void				permission_denied(t_list *head, t_flags *flags)
{
	if (flags->rr == 'R' || flags->no_one_path > 1)
	{
		ft_putstr((char*)head->content);
		ft_putstr(":\n");
	}
	ft_putstr("ft_ls: ");
	ft_putstr((char*)head->content);
	ft_putstr(": Permission denied\n");
	errno = 0;
}

int					get_space(t_dir *head)
{
	int len;

	len = 0;
	while (head)
	{
		if (len < head->len)
			len = head->len;
		head = head->next;
	}
	return (len);
}

int					max_name_len(t_dir *head)
{
	int				len;
	int				max_len;

	max_len = 0;
	while (head)
	{
		len = ft_strlen(head->name);
		max_len = (len > max_len) ? len : max_len;
		head = head->next;
	}
	return (max_len);
}
