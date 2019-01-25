/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:01:04 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/03 14:08:42 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_files	*files_from_dir(int args, char *dir)
{
	DIR				*directory;
	struct dirent	*d;
	t_files			*tr;

	directory = opendir(dir);
	if (directory == NULL)
	{
		print_error_start(dir);
		perror(NULL);
		exit(1);
	}
	tr = new_t_files();
	while ((d = readdir(directory)) != NULL)
	{
		if (args & 2 || d->d_name[0] != '.')
			add_file(tr, dir, ft_strdup(d->d_name));
	}
	closedir(directory);
	free(dir);
	return (tr);
}

static quad_t	get_blocks(t_files *f)
{
	unsigned int	i;
	quad_t			blocks;

	i = 0;
	blocks = 0;
	while (i < f->size)
	{
		blocks += f->files[i]->stats->st_blocks;
		i++;
	}
	return (blocks);
}

void			display_dir(t_files *files, t_args *args, unsigned int i,
		int s)
{
	t_files *df;
	quad_t	blocks;
	char	*path;
	t_file	*file;

	file = files->files[i];
	path = ft_strmcat(file->path, file->name);
	if (files->size > 1)
		ft_printf("%s:\n", path + 2);
	df = files_from_dir(s, path);
	if ((s & 1) == 1)
	{
		blocks = get_blocks(df);
		if (blocks > 0)
			ft_printf("total: %lld\n", get_blocks(df));
	}
	ls(args, df, (s & 4) == 4);
}
