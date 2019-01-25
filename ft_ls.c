/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:23:07 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/03 14:13:35 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	add_args(char **argv, t_args *args, t_files *files)
{
	int		i;
	char	*c;
	int		m;
	int		f;

	i = 1;
	m = 0;
	f = 0;
	while (argv[i])
	{
		c = argv[i];
		if (!m && c[0] == '-')
		{
			if (!add_arg(args, &c[1]))
				return (-1);
		}
		else
		{
			m = 1;
			add_file(files, ".", ft_strdup(c));
			f++;
		}
		i++;
	}
	return (f);
}

static int	is_end(t_files *files)
{
	unsigned int	i;
	t_file			*f;

	i = 0;
	while (i < files->size)
	{
		f = files->files[i];
		if ((S_IFDIR & f->stats->st_mode) &&
			(ft_strcmp(".", f->name) && ft_strcmp("..", f->name)))
			return (1);
		i++;
	}
	return (0);
}

void		ls(t_args *args, t_files *files, int r)
{
	sort(files, args);
	if (r == 1 && is_end(files))
	{
		display(files, args, 0);
		ft_printf("\n");
	}
	display(files, args, r);
	if (r == -1)
		free_t_args(args);
	free_t_files(files);
}

int			main(int argc, char **argv)
{
	t_args	*args;
	t_files	*files;
	int		ac;

	argc = 0;
	args = new_t_args('\0');
	files = new_t_files();
	ac = add_args(argv, args, files);
	if (ac == -1)
	{
		ft_putstr_fd("usage: ft_ls [-Ralrt] [file ...]\n", 2);
		exit(1);
	}
	if (ac == 0)
		add_file(files, ".", ft_strdup("."));
	ls(args, files, -1);
	return (0);
}
