/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:10:10 by cwing             #+#    #+#             */
/*   Updated: 2020/05/16 15:40:47 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			up_t_dir(t_dir *new_elem, t_stat *stat_, char *full_name)
{
	new_elem->links = stat_->st_nlink;
	new_elem->u_name = get_user_name(stat_->st_uid);
	new_elem->u_group = get_group(stat_->st_gid);
	new_elem->chmod = get_chmod(stat_->st_mode);
	new_elem->next = NULL;
	new_elem->size = ft_itoa((int)stat_->st_size);
	new_elem->len = ft_strlen(new_elem->size);
	get_all_time(new_elem, stat_);
	new_elem->blocks = stat_->st_blocks;
	if (new_elem->chmod[0] == 'l')
	{
		if ((new_elem->linkpath = ft_strnew(LINK_MAX)) &&
			readlink(full_name, new_elem->linkpath, LINK_MAX) > 0)
			NULL;
	}
	else
		new_elem->linkpath = NULL;
}

t_dir				*new_t_dir(char *name, char *path, t_flags **flags)
{
	t_stat			stat_;
	t_dir			*new_elem;
	char			*full_name;

	new_elem = (t_dir*)malloc(sizeof(t_dir));
	full_name = NULL;
	full_name = get_full_name(path, name);
	if (lstat(full_name, &stat_) == 0)
	{
		up_t_dir(new_elem, &stat_, full_name);
		new_elem->name = ft_strnew(MAXNAMLEN);
		ft_strncpy(new_elem->name, name, MAXNAMLEN);
		new_elem->flags = *flags;
	}
	else
		ft_memdel((void**)&new_elem);
	ft_memdel((void**)&full_name);
	return (new_elem);
}

static void			push_back(t_dir **head, t_dir *new_elem)
{
	t_dir			*temp;

	if (head && (*head == NULL))
	{
		*head = new_elem;
		return ;
	}
	temp = *head;
	if (new_elem)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_elem;
		new_elem = NULL;
	}
}

void				free_t_dir(t_dir **src)
{
	t_dir			*head;
	t_dir			*to_del;

	head = *src;
	while (head)
	{
		to_del = head;
		ft_memdel((void**)&head->chmod);
		ft_memdel((void**)&head->u_group);
		ft_memdel((void**)&head->u_name);
		ft_memdel((void**)&head->time_mod);
		ft_memdel((void**)&head->name);
		ft_memdel((void**)&head->linkpath);
		ft_memdel((void**)&head->size);
		head = head->next;
		ft_memdel((void**)&to_del);
	}
	*src = NULL;
	src = NULL;
}

t_dir				*get_dir_list(char *path, t_flags **flags)
{
	t_dir			*head;
	t_dir			*new_e;
	DIR				*dir;
	t_dirent		*dirent_;

	head = NULL;
	new_e = NULL;
	if (path && (dir = opendir(path)))
	{
		while ((dirent_ = readdir(dir)))
		{
			new_e = new_t_dir(dirent_->d_name, path, flags);
			if (new_e)
				push_back(&head, new_e);
			else
			{
				closedir(dir);
				free_t_dir(&head);
				return (head);
			}
		}
		closedir(dir);
	}
	return (head);
}
