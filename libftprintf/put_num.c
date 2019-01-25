/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:24:49 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/28 21:29:19 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static T					get_type(t_format *format, char c)
{
	T	tr;

	if (format->hh)
		tr = hh(c);
	else if (format->h)
		tr = h(c);
	else if (format->l)
		tr = l(c);
	else if (format->ll)
		tr = ll(c);
	else
		tr = no_flag(c);
	return (tr);
}

static unsigned long long	get_unsigned_arg(va_list list, T type)
{
	if (type == UNSIGNED_CHAR)
		return ((unsigned long long)va_arg(list, int));
	else if (type == UNSIGNED_SHORT)
		return ((unsigned long long)va_arg(list, int));
	else if (type == UNSIGNED_LONG)
		return ((unsigned long long)va_arg(list, unsigned long));
	else if (type == UNSIGNED_LONG_LONG)
		return ((unsigned long long)va_arg(list, unsigned long long));
	else
		return ((unsigned long long)va_arg(list, unsigned int));
}

static unsigned long long	get_arg(va_list list, T type, int *is_negative)
{
	if (type == CHAR)
		return (c_arg(list, is_negative));
	else if (type == SHORT)
		return (s_arg(list, is_negative));
	else if (type == LONG)
		return (l_arg(list, is_negative));
	else if (type == LONG_LONG)
		return (ll_arg(list, is_negative));
	else
		return (i_arg(list, is_negative));
}

static unsigned long long	get_ull(va_list list, T type, int *is_negative)
{
	if (type == UNSIGNED_CHAR || type == UNSIGNED_SHORT ||
		type == UNSIGNED_LONG || type == UNSIGNED_LONG_LONG ||
		type == UNSIGNED_INTEGER)
		return (get_unsigned_arg(list, type));
	else
		return (get_arg(list, type, is_negative));
}

void						put_num(va_list list, t_format *format, int *chars,
							char c)
{
	T		type;
	char	*num;
	int		is_negative;

	if (c == 'i')
		c = 'd';
	type = get_type(format, c);
	is_negative = 0;
	format->zero = format->zero && !format->minus;
	format->plus = format->plus && c != 'u';
	format->space = format->space && c != 'u' &&
		(c != 'd' || (c == 'd' && !format->plus && format->width == -1));
	num = get_num_str(&is_negative, get_ull(list, type, &is_negative), c,
			format);
	print_with_flags(num, format, chars);
	free(num);
}
