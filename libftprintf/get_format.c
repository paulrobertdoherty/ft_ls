/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:44:32 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/24 19:05:50 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_format	*new_t_format(void)
{
	t_format	*tr;

	tr = (t_format *)malloc(sizeof(t_format));
	if (tr == NULL)
		return (NULL);
	tr->hash = 0;
	tr->plus = 0;
	tr->minus = 0;
	tr->hh = 0;
	tr->h = 0;
	tr->l = 0;
	tr->ll = 0;
	tr->L = 0;
	tr->precision = -1;
	tr->width = -1;
	tr->zero = 0;
	tr->space = 0;
	return (tr);
}

static void		read_format_string(char *str, t_format *format)
{
	int	i;

	i = 0;
	add_flags(str, format);
	add_zero(str, format);
	add_width(str, format);
	add_precision(str, format);
}

t_format		*get_format(char *str, int j)
{
	char		*split;
	t_format	*format;

	split = ft_strsub(str, 0, j);
	if (split == NULL)
		return (NULL);
	format = new_t_format();
	if (format == NULL)
		return (NULL);
	read_format_string(split, format);
	free(split);
	return (format);
}
