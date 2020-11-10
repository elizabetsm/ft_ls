/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:41:31 by efleta            #+#    #+#             */
/*   Updated: 2020/05/18 19:17:42 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				no_such_file(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": No such file or directory\n");
}

void				get_all_time(t_dir *elem, t_stat *stat_)
{
	elem->time_mod = get_time(&stat_->st_mtime);
	elem->timemod_d = stat_->st_mtime;
}

void				check_names(t_list *head, t_flags **flags)
{
	DIR				*dir;

	dir = NULL;
	while (head)
	{
		if (((char*)head->content)[0] == '\0')
		{
			no_such_file((char*)(head->content));
			head = head->next;
			continue;
		}
		dir = opendir((char*)(head->content));
		if (dir)
			closedir(dir);
		else if (errno == 13)
			permission_denied(head, *flags);
		else if (open_single_file((char*)(head->content), flags))
			NULL;
		else
			no_such_file((char*)(head->content));
		head = head->next;
	}
}

blkcnt_t			summ_blocks(t_dir *head)
{
	blkcnt_t		summ;

	summ = 0;
	while (head)
	{
		if (head->flags->a == '0' && head->name[0] == '.')
		{
			head = head->next;
			continue;
		}
		summ += head->blocks;
		head = head->next;
	}
	return (summ);
}

int					open_single_file(char *path, t_flags **flags)
{
	t_dir			*single;

	single = NULL;
	if (path[0] == '/')
		single = new_t_dir(path, "", flags);
	else
		single = new_t_dir(path, "./", flags);
	if (single)
	{
		main_print(single);
		free_t_dir(&single);
		return (1);
	}
	return (0);
}
