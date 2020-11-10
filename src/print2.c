/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:11:58 by efleta            #+#    #+#             */
/*   Updated: 2020/05/16 15:43:15 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				f_print(t_dir *head)
{
	if (head->chmod[0] == 'd')
		ft_putchar('/');
	else if (head->chmod[0] == 'l')
		ft_putchar('@');
	else if (head->chmod[3] == 'x' || head->chmod[6] == 'x' ||
			head->chmod[9] == 'x')
		ft_putchar('*');
}

static void			ft_putstr_c(char *src, char *color)
{
	ft_putstr(color);
	ft_putstr(src);
	ft_putstr(STD_T);
}

void				ft_printnum(int num)
{
	char			*buff;

	buff = NULL;
	if ((buff = ft_itoa(num)))
		ft_putstr(buff);
	ft_memdel((void**)&buff);
}

void				print_name(t_dir *head)
{
	if (head->flags->gg == 'G')
	{
		if (head->chmod[0] == 'd')
			ft_putstr_c(head->name, BLU_T);
		else if (head->chmod[0] == '-' &&
		(head->chmod[3] == 'x' || head->chmod[6] == 'x' ||
		head->chmod[9] == 'x'))
			ft_putstr_c(head->name, GRE_T);
		else if (head->chmod[0] == 'l')
			ft_putstr_c(head->name, YWL_T);
		else
			ft_putstr_c(head->name, STD_T);
	}
	else
		ft_putstr(head->name);
	if (head->flags->ff == 'F')
		f_print(head);
}

void				print_space(t_dir *head, int len)
{
	int i;

	i = len - ft_strlen(head->size);
	ft_putchar(' ');
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}
