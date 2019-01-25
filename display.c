/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 22:11:34 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/03 14:20:51 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static unsigned int	get_stats(t_args *args)
{
	unsigned int	tr;
	t_args			*a;

	a = args;
	tr = 0;
	while (a)
	{
		if (a->arg == 'l')
			tr = tr | 1;
		if (a->arg == 'a')
			tr = tr | 2;
		if (a->arg == 'R')
			tr = tr | 4;
		a = a->next;
	}
	return (tr);
}

int					ldir(int r, t_file *f)
{
	return (r == -1 ||
			(r && ft_strcmp(f->name, ".") && ft_strcmp(f->name, "..")));
}

static void			largest_size(t_files *files, int *l_s, int *s_s)
{
	int				cl;
	int				cl2;
	unsigned int	i;
	t_file			*f;

	cl = 0;
	cl2 = 0;
	i = 0;
	while (i < files->size)
	{
		f = files->files[i];
		cl = size_len(f->stats->st_nlink);
		cl2 = size_len(f->stats->st_size);
		if (cl > *l_s)
			*l_s = cl;
		if (cl2 > *s_s)
			*s_s = cl2;
		i++;
	}
}

static int			has_directories(t_files *files, int r)
{
	unsigned int	i;
	t_file			*f;

	i = 0;
	while (i < files->size)
	{
		f = files->files[i];
		if (ldir(r, f) && S_IFDIR & f->stats->st_mode)
			return (1);
		i++;
	}
	return (0);
}

void				display(t_files *f, t_args *args, int r)
{
	unsigned int	i;
	int				s;
	int				s_s;
	int				l_s;
	int				d;

	i = 0;
	s = (int)get_stats(args);
	s_s = 0;
	l_s = 0;
	largest_size(f, &l_s, &s_s);
	d = has_directories(f, r);
	while (i < f->size)
	{
		if (ldir(r, f->files[i]) && S_IFDIR & f->files[i]->stats->st_mode)
			display_dir(f, args, i, s);
		else if (!d)
		{
			if (s & 1)
				display_long(f->files[i], l_s, s_s);
			else
				ft_printf("%s\n", f->files[i]->name);
		}
		i++;
	}
}
