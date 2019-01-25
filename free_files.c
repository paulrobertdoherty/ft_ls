/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:06:46 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/10 19:06:48 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_t_files(t_files *files)
{
	t_files			*f;
	unsigned int	i;

	f = files;
	i = 0;
	while (i < f->size)
	{
		free(f->files[i]->stats);
		free(f->files[i]->path);
		free(f->files[i]->name);
		free(f->files[i]);
		i++;
	}
	free(f->files);
	free(f);
}
