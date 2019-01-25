/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:32:32 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/18 12:16:37 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	swap_file(t_file *a, t_file *b, int tr)
{
	t_file	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return (tr);
}

static int	partition(t_file **f, int s, int e, t_comparison cmp)
{
	int	l;
	int	r;
	int	cl;
	int	cr;

	l = s;
	r = e - 1;
	while (l < r)
	{
		cl = cmp(f[l], f[e]) <= 0;
		cr = cmp(f[r], f[e]) >= 0;
		if (cl)
			l++;
		if (cr)
			r--;
		if (!cl && !cr)
			swap_file(f[l], f[r], 0);
	}
	if (l == r)
	{
		if (cmp(f[l], f[e]) >= 0)
			return (swap_file(f[l], f[e], l));
		return (swap_file(f[l + 1], f[e], l + 1));
	}
	return (swap_file(f[l], f[e], l));
}

static void	qs(t_file **f, t_comparison cmp, int s, int e)
{
	int	pi;

	if (s < e)
	{
		pi = partition(f, s, e, cmp);
		if (pi > 0)
			qs(f, cmp, s, pi - 1);
		qs(f, cmp, pi + 1, e);
	}
}

void		quicksort(t_files *f, t_comparison cmp)
{
	if (f->size > 0)
		qs(f->files, cmp, 0, (int)f->size - 1);
}
