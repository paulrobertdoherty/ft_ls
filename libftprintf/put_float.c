/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:56:10 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/29 12:13:26 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	llof(va_list list, t_format *format, int *chars)
{
	long double			num;
	unsigned long long	first;
	int					in;

	num = va_arg(list, long double);
	in = 0;
	first = (unsigned long long)num;
	if (num < 0)
	{
		in = 1;
		first = (unsigned long long)-num;
	}
	*chars += print_float(first, num, format, in);
	return (1);
}

static int	lof(va_list list, t_format *format, int *chars)
{
	double				num;
	unsigned long long	first;
	int					in;

	num = va_arg(list, double);
	in = 0;
	first = (unsigned long long)num;
	if (num < 0)
	{
		in = 1;
		first = (unsigned long long)-num;
	}
	*chars += print_float(first, (long double)num, format, in);
	return (1);
}

int			put_float(va_list list, t_format *format, int *chars)
{
	if (format->L)
		return (llof(list, format, chars));
	return (lof(list, format, chars));
}
