/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:31:26 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/29 23:25:26 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*get_space(int space, int n, int z)
{
	char	*tr;
	int		i;

	if (n < 0)
		n = 0;
	tr = ft_strnew(n + space);
	i = 0;
	if (space)
		tr[0] = ' ';
	while (i < n)
	{
		if (z)
			tr[i + space] = '0';
		else
			tr[i + space] = ' ';
		i++;
	}
	return (tr);
}

static char	*get_header(int in, ull n, char c, t_format *format)
{
	if (format->plus && !in && (c == 'd' || c == 'u' || c == 'f'))
		return (ft_strdup("+"));
	if (format->hash)
	{
		if (c == 'o')
			return (ft_strdup("0"));
		if (c == 'x' && n)
			return (ft_strdup("0x"));
		if (c == 'X' && n)
			return (ft_strdup("0X"));
	}
	return (ft_strnew(0));
}

static char	*add_strings(char *one, char *two, char *str)
{
	char	*m;
	char	*tr;

	m = ft_strjoin(one, two);
	ft_strdel(&one);
	ft_strdel(&two);
	tr = ft_strjoin(m, str);
	ft_strdel(&m);
	ft_strdel(&str);
	return (tr);
}

static char	*get_space_string(char *str, t_format *format, int l)
{
	char	*space;

	if (format->precision == -1)
	{
		if (format->width == -1)
			space = get_space(format->space, 0, 0);
		else
			space = get_space(format->space, format->width - l,
					format->zero || format->precision > l);
	}
	else
		space = get_space(format->space, (str[0] == '-') + format->precision -
				l, format->zero || format->precision > l);
	return (space);
}

char		*get_front(char *str, ull n, char c, t_format *format)
{
	char	*header;
	char	*space;
	int		l;

	if (!format->precision && (c != 'd' || (c == 'd' && !n)))
		return (ft_strnew(0));
	header = get_header(str[0] == '-', n, c, format);
	l = ft_strlen(str) + ft_strlen(header);
	if (c == 'd' && format->plus && l == format->precision)
		format->precision++;
	space = get_space_string(str, format, l);
	if (format->zero || format->precision > l)
		return (add_strings(header, space, ft_strdup(str)));
	if (format->minus && !(format->zero || format->precision > l))
		return (add_strings(header, ft_strdup(str), space));
	return (add_strings(space, header, ft_strdup(str)));
}
