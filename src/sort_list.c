/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:47:15 by cwing             #+#    #+#             */
/*   Updated: 2020/05/16 15:41:37 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			swap(t_dir **h, t_dir **temp_a, t_dir **temp_b, t_dir **b)
{
	(*temp_a)->next = (*temp_b)->next;
	(*temp_b)->next = (*temp_a);
	if (!(*b))
		*h = (*temp_b);
	if ((*b))
		(*b)->next = (*temp_b);
}

static void			sort_d_asci(t_dir **head)
{
	t_dir			*temp_a;
	t_dir			*temp_b;
	t_dir			*back;
	int				chek;

	temp_a = *head;
	temp_b = NULL;
	back = NULL;
	chek = 0;
	while (temp_a)
	{
		temp_b = temp_a->next;
		if (temp_b && (ft_strncmp(temp_a->name, temp_b->name, MAXNAMLEN) > 0))
		{
			swap(head, &temp_a, &temp_b, &back);
			chek = 1;
		}
		back = temp_a;
		temp_a = temp_b;
	}
	if (chek == 1)
		sort_d_asci(head);
}

static void			sort_d_rev(t_dir **head)
{
	t_dir			*temp_a;
	t_dir			*temp_b;
	t_dir			*temp_c;

	temp_a = NULL;
	temp_b = *head;
	while (temp_b)
	{
		temp_c = temp_b->next;
		temp_b->next = temp_a;
		temp_a = temp_b;
		temp_b = temp_c;
	}
	*head = temp_a;
}

static void			sort_d_time(t_dir **head)
{
	t_dir			*temp_a;
	t_dir			*temp_b;
	t_dir			*back;
	int				chek;

	temp_a = *head;
	back = NULL;
	chek = 0;
	while (temp_a)
	{
		temp_b = temp_a->next;
		if (temp_b && (temp_a->timemod_d > temp_b->timemod_d))
		{
			swap(head, &temp_a, &temp_b, &back);
			chek = 1;
		}
		back = temp_a;
		temp_a = temp_b;
	}
	if (chek == 1)
		sort_d_time(head);
}

void				sort_dirs(t_dir **head)
{
	sort_d_asci(head);
	if ((*head)->flags->r == 'r')
		sort_d_rev(head);
	else if ((*head)->flags->t == 't')
	{
		sort_d_time(head);
		sort_d_rev(head);
	}
}
