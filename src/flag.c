/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:47:56 by cwing             #+#    #+#             */
/*   Updated: 2020/05/18 20:38:35 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ilegal_flags(t_flags **flags)
{
	if ((*flags)->illegal != '0')
	{
		ft_putstr("./ft_ls: illegal option -- ");
		ft_putchar((*flags)->illegal);
		ft_putchar('\n');
		ft_putstr("usage: ./ft_ls [-atrlRGF] [file ...]\n");
		ft_memdel((void**)flags);
	}
}

int					is_flag(char flag)
{
	if (flag == 'l' || flag == 'R' || flag == 'a' || flag == 'r' ||
	flag == 'G' || flag == '1' || flag == 't' || flag == 'F')
		return (1);
	else
		return (0);
}

static void			null_flags(t_flags *flags)
{
	flags->a = '0';
	flags->gg = '0';
	flags->l = '0';
	flags->rr = '0';
	flags->r = '0';
	flags->t = '0';
	flags->one = '0';
	flags->ff = '0';
	flags->illegal = '0';
}

static int			add_flag(char *arg, t_flags *flags)
{
	int				i;

	i = 0;
	while (arg[++i])
	{
		if (!is_flag(arg[i]) && flags->illegal == '0')
			flags->illegal = arg[i];
		if (arg[i] == 'l')
		{
			flags->one = '0';
			flags->l = 'l';
		}
		if (arg[i] == '1')
		{
			flags->one = '1';
			flags->l = '0';
		}
		flags->rr = (arg[i] == 'R') ? 'R' : flags->rr;
		flags->a = (arg[i] == 'a') ? 'a' : flags->a;
		flags->r = (arg[i] == 'r') ? 'r' : flags->r;
		flags->t = (arg[i] == 't') ? 't' : flags->t;
		flags->gg = (arg[i] == 'G') ? 'G' : flags->gg;
		flags->ff = (arg[i] == 'F') ? 'F' : flags->ff;
	}
	return ((flags->illegal == '0') ? 1 : 0);
}

t_flags				*get_flags(int argc, char **argv)
{
	t_flags			*flags;
	int				i;

	i = 0;
	if ((flags = malloc(sizeof(t_flags))))
	{
		null_flags(flags);
		while (++i < argc)
		{
			if (argv[i][0] == '-')
				add_flag(argv[i], flags);
			else
				break ;
		}
	}
	ilegal_flags(&flags);
	return (flags);
}
