/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:07:04 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/18 16:02:41 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_comparison	get_sorting_func(t_args *args)
{
	t_comparison	cmp;
	t_args			*a;
	int				reverse;

	cmp = &alphabetical;
	a = args;
	reverse = 0;
	while (a)
	{
		if (a->arg == 'r')
			reverse = 1;
		if (a->arg == 't')
			cmp = &time_modified;
		a = a->next;
	}
	if (reverse)
	{
		if (cmp == &alphabetical)
			cmp = &reverse_alphabetical;
		else if (cmp == &time_modified)
			cmp = &reverse_time_modified;
	}
	return (cmp);
}

void				sort(t_files *files, t_args *args)
{
	quicksort(files, get_sorting_func(args));
}
