/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:07:13 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/18 16:02:24 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		alphabetical(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name));
}

int		reverse_alphabetical(t_file *a, t_file *b)
{
	return (-alphabetical(a, b));
}

int		time_modified(t_file *a, t_file *b)
{
	time_t	d;

	d = (b->stats->st_mtimespec.tv_sec -
			a->stats->st_mtimespec.tv_sec);
	if (d != 0)
		return (d);
	return ((int)(b->stats->st_mtimespec.tv_nsec -
			a->stats->st_mtimespec.tv_nsec));
}

int		reverse_time_modified(t_file *a, t_file *b)
{
	return (-time_modified(a, b));
}
