/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:01:13 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/18 16:32:18 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_file_mode(mode_t mode, char *path)
{
	if (S_ISLNK(mode))
		ft_printf("l");
	else if (S_ISREG(mode))
		ft_printf("-");
	else if (S_ISDIR(mode))
		ft_printf("d");
	ft_printf("%c", (S_IRUSR & mode) ? 'r' : '-');
	ft_printf("%c", (S_IWUSR & mode) ? 'w' : '-');
	ft_printf("%c", (S_IXUSR & mode) ? 'x' : '-');
	ft_printf("%c", (S_IRGRP & mode) ? 'r' : '-');
	ft_printf("%c", (S_IWGRP & mode) ? 'w' : '-');
	ft_printf("%c", (S_IXGRP & mode) ? 'x' : '-');
	ft_printf("%c", (S_IROTH & mode) ? 'r' : '-');
	ft_printf("%c", (S_IWOTH & mode) ? 'w' : '-');
	ft_printf("%c", (S_IXOTH & mode) ? 'x' : '-');
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW))
		ft_printf("@");
	else
		ft_printf(" ");
	ft_printf(" ");
	free(path);
}

static void	display_spaces(int spaces)
{
	int i;

	i = 0;
	while (i < spaces)
	{
		ft_printf(" ");
		i++;
	}
	spaces = 0;
}

int			size_len(unsigned long long size)
{
	int	tr;

	if (size == 0)
		return (1);
	tr = 0;
	while (size > 0)
	{
		tr++;
		size /= 10;
	}
	return (tr);
}

static void	print_time(time_t t)
{
	char *ts;

	ts = ctime(&t);
	ft_printf("%.6s", ts + 4);
	if (time(NULL) > t + 15552000 || time(NULL) < t)
		ft_printf("  %ld", ((t % 31536000) / 31536000) + 1970);
	else
		ft_printf("%.6s", ts + 10);
	ft_printf(" ");
}

void		display_long(t_file *file, int l_spaces, int s_spaces)
{
	print_file_mode(file->stats->st_mode, ft_strmcat(file->path,
				file->name));
	display_spaces(l_spaces - size_len(file->stats->st_nlink));
	ft_printf("%d ", file->stats->st_nlink);
	ft_printf("%s  ", getpwuid(file->stats->st_uid)->pw_name);
	ft_printf("%s  ", getgrgid(file->stats->st_gid)->gr_name);
	display_spaces(s_spaces - size_len(file->stats->st_size));
	ft_printf("%lld ", file->stats->st_size);
	print_time(file->stats->st_mtimespec.tv_sec);
	print_path(file);
}
