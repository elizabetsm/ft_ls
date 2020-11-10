/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:16:40 by cwing             #+#    #+#             */
/*   Updated: 2020/05/16 13:55:34 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			get_file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

char				*get_time(time_t *time_)
{
	char			*str_time;
	char			*str;
	int				i;

	str_time = NULL;
	i = 0;
	str_time = ctime(time_) + 4;
	if ((str = ft_strnew(13)))
	{
		while (i < 12)
		{
			str[i] = str_time[i];
			i++;
		}
	}
	return (str);
}

char				*get_chmod(mode_t mode)
{
	char			*chmod;

	chmod = NULL;
	if ((chmod = ft_strnew(12)))
	{
		chmod[0] = get_file_type(mode);
		chmod[1] = (S_IRUSR & mode) ? 'r' : '-';
		chmod[2] = (S_IWUSR & mode) ? 'w' : '-';
		chmod[3] = (S_IXUSR & mode) ? 'x' : '-';
		chmod[4] = (S_IRGRP & mode) ? 'r' : '-';
		chmod[5] = (S_IWGRP & mode) ? 'w' : '-';
		chmod[6] = (S_IXGRP & mode) ? 'x' : '-';
		chmod[7] = (S_IROTH & mode) ? 'r' : '-';
		chmod[8] = (S_IWOTH & mode) ? 'w' : '-';
		chmod[9] = (S_IXOTH & mode) ? 'x' : '-';
		chmod[10] = ' ';
		if (S_ISUID & mode)
			chmod[3] = chmod[3] == '-' ? 'S' : 's';
		if (S_ISGID & mode)
			chmod[6] = chmod[6] == '-' ? 'S' : 's';
		if (S_ISVTX & mode)
			chmod[9] = chmod[9] == '-' ? 'T' : 't';
	}
	return (chmod);
}

char				*get_user_name(uid_t uid)
{
	struct passwd	*pass_t;
	char			*user_name;

	pass_t = NULL;
	user_name = NULL;
	if ((pass_t = getpwuid(uid)) &&
		(user_name = ft_strnew(MAXNAMLEN)))
	{
		user_name = ft_strncpy(user_name, pass_t->pw_name, MAXNAMLEN);
	}
	return (user_name);
}

char				*get_group(gid_t gid)
{
	struct group	*group_t;
	char			*group;

	group_t = NULL;
	group = NULL;
	if ((group_t = getgrgid(gid)) &&
		(group = ft_strnew(ft_strlen(group_t->gr_name) + 1)))
	{
		group = ft_strcpy(group, group_t->gr_name);
	}
	return (group);
}
