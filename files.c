/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:29:22 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/11 20:55:29 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files			*new_t_files(void)
{
	t_files	*files;
	t_file	**list;

	files = (t_files *)malloc(sizeof(t_files));
	send_memory_error(files);
	files->size = 0;
	list = (t_file **)malloc(sizeof(t_file *) * 3);
	send_memory_error(list);
	list[0] = NULL;
	list[1] = NULL;
	list[2] = NULL;
	files->files = list;
	return (files);
}

static int		is_power_of_two(unsigned int n)
{
	return (n && !(n & (n - 1)));
}

static t_file	**double_list(t_files *files)
{
	t_files			*tr;
	t_file			**f;
	unsigned int	i;

	tr = files;
	f = (t_file **)malloc(sizeof(t_file *) * ((tr->size * 2) + 1));
	send_memory_error(f);
	i = 0;
	while (i <= tr->size * 2)
	{
		if (tr->files[i])
			f[i] = tr->files[i];
		else
			f[i] = NULL;
		i++;
	}
	free(tr->files);
	tr->files = f;
	return (tr->files);
}

static t_file	*get_file(char *path, char *file)
{
	t_file		*tr;
	t_stats		*buf;
	char		*fp;

	tr = (t_file *)malloc(sizeof(t_file));
	send_memory_error(tr);
	buf = (t_stats *)malloc(sizeof(t_stats));
	send_memory_error(buf);
	tr->path = ft_strdup(path);
	tr->name = file;
	tr->stats = buf;
	fp = ft_strmcat(path, file);
	if (lstat(fp, buf) != 0)
	{
		print_error_start(file);
		perror(NULL);
		return (NULL);
	}
	free(fp);
	return (tr);
}

void			add_file(t_files *files, char *path, char *file)
{
	t_files	*f;
	t_file	*ta;

	ta = get_file(path, file);
	if (ta == NULL)
		return ;
	f = files;
	if (f->size == 0)
	{
		f->files[0] = ta;
		(f->size)++;
		return ;
	}
	if (is_power_of_two(f->size))
		f->files = double_list(f);
	f->files[f->size] = ta;
	(f->size)++;
}
