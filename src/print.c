/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 20:11:44 by cwing             #+#    #+#             */
/*   Updated: 2020/05/18 20:01:58 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				simple_print(t_dir *head, char all_mod, int col)
{
	int				i;
	int				space;
	int				max_len;

	i = 1;
	max_len = 3 + max_name_len(head);
	while (head)
	{
		if (all_mod == '0' && head->name[0] == '.')
		{
			head = head->next;
			continue;
		}
		space = max_len - ft_strlen(head->name);
		print_name(head);
		while (space--)
			ft_putchar(' ');
		if (col > max_len && (i % (int)(col / max_len)) == 0)
			ft_putchar('\n');
		i++;
		head = head->next;
	}
	ft_putchar('\n');
}

static void			print_line(t_dir *head, int len)
{
	ft_putstr(head->chmod);
	ft_putchar(' ');
	ft_printnum((int)head->links);
	ft_putchar('\t');
	ft_putstr(head->u_name);
	ft_putchar('\t');
	ft_putstr(head->u_group);
	print_space(head, len);
	ft_putstr(head->size);
	ft_putchar(' ');
	ft_putstr(head->time_mod);
	ft_putchar(' ');
	print_name(head);
	if (head->chmod[0] == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(head->linkpath);
	}
	ft_putchar('\n');
}

void				all_print(t_dir *head, char all_mod, int len)
{
	if (head->next != NULL)
	{
		ft_putstr("total ");
		ft_printnum(summ_blocks(head));
		ft_putchar('\n');
	}
	while (head)
	{
		if (all_mod == '0' && head->name[0] == '.')
		{
			head = head->next;
			continue;
		}
		print_line(head, len);
		head = head->next;
	}
}

void				main_print(t_dir *head)
{
	int				len;
	struct winsize	windows;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &windows);
	len = get_space(head);
	if (head->flags->l == 'l')
		all_print(head, head->flags->a, len);
	else if (head->flags->one == '1')
		print_one(head, head->flags->a);
	else
		simple_print(head, head->flags->a, (int)windows.ws_col);
}

void				print_one(t_dir *head, char all_mod)
{
	while (head)
	{
		if (all_mod == '0' && head->name[0] == '.')
		{
			head = head->next;
			continue;
		}
		print_name(head);
		ft_putchar('\n');
		head = head->next;
	}
}
