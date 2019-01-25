/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:03:28 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/24 11:50:06 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		put_string(va_list list, t_format *format, int *chars)
{
	char	*tr;
	char	*g;
	int		pre;

	g = va_arg(list, char *);
	if (g == NULL)
		g = "(null)";
	pre = format->precision;
	if (pre == -1)
		pre = 0;
	tr = pre != 0 ? ft_strsub(g, 0, pre) : ft_strdup(g);
	print_with_flags(tr, format, chars);
	free(tr);
}
