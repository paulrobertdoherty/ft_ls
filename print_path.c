/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:59:58 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/02 21:45:14 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_path(t_file *f)
{
	char	path_buffer[PATH_MAX];
	size_t	path_length;

	ft_printf("%s", f->name);
	if (S_ISLNK(f->stats->st_mode))
	{
		path_length = readlink(ft_strmcat(f->path,
					f->name), path_buffer, sizeof(path_buffer) - 1);
		path_buffer[path_length] = '\0';
		ft_printf(" -> %s", path_buffer);
	}
	ft_printf("\n");
}
