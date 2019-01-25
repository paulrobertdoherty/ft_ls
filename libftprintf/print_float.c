/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:57:52 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/29 23:08:11 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static long double	rhte(long double num, int nums, long double ta)
{
	int	j;

	if (nums % 10 < 5)
		return (num);
	else if (nums % 10 > 5)
		return (num + ta);
	else
	{
		j = ((nums % 1000) - (nums % 100)) / 100;
		if (j % 2 == 0)
			return (num);
		return (num + ta);
	}
}

static long double	round_half_to_even(long double num, int precision)
{
	int			nums;
	int			i;
	int			j;
	long double	ta;
	long double	n;

	if (num < 0)
		num = -num;
	n = num - (long)num;
	ta = 5.0;
	i = 0;
	while (i < precision + 1)
	{
		n *= 10;
		if (i < precision - 3)
			n = n - (long)n;
		ta *= 0.1;
		i++;
	}
	return (rhte(num, (int)n, ta));
}

static char			*get_dig_str(long double num, t_format *format)
{
	int		i;
	char	*tr;

	tr = ft_strnew(format->precision);
	i = 0;
	num -= (long)num;
	num *= 10;
	while (i < format->precision)
	{
		tr[i] = (long)num + '0';
		i++;
		num -= (long)num;
		num *= 10;
	}
	return (tr);
}

static t_format		*copy_format(t_format *format)
{
	t_format	*tr;

	tr = (t_format *)malloc(sizeof(t_format));
	tr->hash = 0;
	tr->plus = format->plus;
	tr->minus = format->minus;
	tr->precision = -1;
	tr->width = 0;
	tr->zero = format->zero;
	tr->space = format->space;
	return (tr);
}

int					print_float(unsigned long long first, long double num,
		t_format *format, int is_negative)
{
	char		*f;
	char		*s;
	char		*t;
	t_format	*nf;
	int			chars;

	format->precision = format->precision == -1 ? 6 : format->precision;
	num = round_half_to_even(num, format->precision);
	chars = 0;
	nf = copy_format(format);
	first += ((long)num % 10) - (first % 10);
	f = get_num_str(&is_negative, first, 'f', nf);
	free(nf);
	if (format->hash || format->precision)
		s = ft_strjoin(f, ".");
	else
		s = ft_strdup(f);
	ft_strdel(&f);
	t = ft_strjoin(s, get_dig_str(num, format));
	ft_strdel(&s);
	print_with_flags(t, format, &chars);
	ft_strdel(&t);
	return (chars);
}
